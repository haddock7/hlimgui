package imgui;

import h3d.mat.Texture;
import imgui.ImGui;
import hxd.Key;

private class ImGuiDrawableBuffers {

	public static final instance = new ImGuiDrawableBuffers();

	public var vertex_buffers(default, null) : Array<h3d.Buffer> = [];
	public var index_buffers(default, null) : Array<{
		texture_id:Int, 
		vertex_buffer_id:Int, 
		clip_rect:{x:Int, y:Int, width:Int, height:Int},
		buffer:h3d.Indexes}> = [];

	private var initialized : Bool;
	private var textures : Array<Texture> = [];
	private var font_texture : Texture;

	public function initialize() {
		if (this.initialized) {
			return;
		}

		var font_info:{buffer:hl.Bytes, width:Int, height:Int} = ImGui.initialize(renderDrawListsFromExternal);

		// create font texture
		var texture_size = font_info.width * font_info.height * 4;
		var font_texture_id = registerTexture(Texture.fromPixels(new hxd.Pixels(
			font_info.width, 
			font_info.height, 
			font_info.buffer.toBytes(texture_size),
			hxd.PixelFormat.RGBA)));
		ImGui.setFontTexture(font_texture_id);
		
		this.initialized = true;
	}

	public function dispose() {
		for (index_buffer in this.index_buffers) {
			index_buffer.buffer.dispose();
		}
		this.index_buffers = [];

		for (vertex_buffer in this.vertex_buffers) {
			vertex_buffer.dispose();
		}
		this.vertex_buffers = [];

		for (texture in this.textures) {
			texture.dispose();
		}
		this.textures = [];

		this.initialized = false;
	}

	public function registerTexture(texture : Texture) : Int {
		var texture_id = this.textures.length;
		this.textures.push(texture);
		return texture_id + 1;
	}

	public function getTexture(texture_id) : Texture {
		return this.textures[texture_id-1];
	}

	private function new() {
		this.initialized = false;
	}

	private function renderDrawList(draw_list:{cmd_list:hl.NativeArray<Dynamic>}) {
		var vertex_buffer_index = 0;
		var index_buffer_index = 0;

		for (cmd_index in 0...draw_list.cmd_list.length) {
			var draw_item = draw_list.cmd_list[cmd_index];

			var ext_vertex_buffer:hl.Bytes = draw_item.vertex_buffer;
			var vertex_stride = 8;
			var nb_vertices = Std.int(draw_item.vertex_buffer_size/(vertex_stride*4));

			// create or reuse vertex buffer
			if (vertex_buffer_index >= this.vertex_buffers.length) {
				this.vertex_buffers[vertex_buffer_index] = new h3d.Buffer(nb_vertices, vertex_stride, [RawFormat, Dynamic]);
			} else if (this.vertex_buffers[vertex_buffer_index].vertices < nb_vertices) {
				this.vertex_buffers[vertex_buffer_index].dispose();
				this.vertex_buffers[vertex_buffer_index] = new h3d.Buffer(nb_vertices, vertex_stride, [RawFormat, Dynamic]);
			}

			// update vertex buffer data
			this.vertex_buffers[vertex_buffer_index].uploadBytes(ext_vertex_buffer.toBytes(draw_item.vertex_buffer_size), 0, nb_vertices);

			var draw_objects:hl.NativeArray<Dynamic> = draw_item.draw_objects;

			// read cmd buffers
			for (draw_object_index in 0...draw_objects.length) {
				var draw_object = draw_objects[draw_object_index];
				
				var ext_index_buffer:hl.Bytes = draw_object.index_buffer;
				var nb_indices = Std.int(draw_object.index_buffer_size/2);
				var clip_rect = {
					x: draw_object.clip_left,
					y: draw_object.clip_top,
					width: draw_object.clip_width,
					height: draw_object.clip_height
				}

				// create or reuse index buffer
				if (index_buffer_index >= this.index_buffers.length) {
					this.index_buffers[index_buffer_index] = {
						buffer: new h3d.Indexes(nb_indices), 
						vertex_buffer_id: vertex_buffer_index, 
						clip_rect: clip_rect,
						texture_id: draw_object.texture_id};
				} else if (this.index_buffers[index_buffer_index].buffer.count != nb_indices) {
					this.index_buffers[index_buffer_index].buffer.dispose();
					this.index_buffers[index_buffer_index] = {
						buffer: new h3d.Indexes(nb_indices), 
						vertex_buffer_id: vertex_buffer_index, 
						clip_rect: clip_rect,
						texture_id: draw_object.texture_id
					};
				} else {
					var index_buffer = this.index_buffers[index_buffer_index];
					index_buffer.vertex_buffer_id = vertex_buffer_index;
					index_buffer.texture_id = draw_object.texture_id;
					index_buffer.clip_rect = clip_rect;
				}

				// update index buffer data
				this.index_buffers[index_buffer_index].buffer.uploadBytes(ext_index_buffer.toBytes(draw_object.index_buffer_size), 0, nb_indices);

				index_buffer_index++;
 			}

			vertex_buffer_index++;
		}

		// remove unused buffers
		if (index_buffer_index < this.index_buffers.length) {
			for (i in index_buffer_index...this.index_buffers.length) {
				this.index_buffers[i].buffer.dispose();
			}
			this.index_buffers.resize(index_buffer_index);
		}
		if (vertex_buffer_index < this.vertex_buffers.length) {
			for (i in vertex_buffer_index...this.vertex_buffers.length) {
				this.vertex_buffers[i].dispose();
			}
			this.vertex_buffers.resize(vertex_buffer_index);
		}
	}

    private static function renderDrawListsFromExternal(draw_list:{cmd_list:hl.NativeArray<Dynamic>}) {
		instance.renderDrawList(draw_list);
	}
}

class ImGuiDrawable extends h2d.Drawable {

	var empty_tile : h2d.Tile;
	var mouse_down = [false, false];
	var mouse_x : Float;
	var mouse_y : Float;
	var mouse_delta : Float;
	var keycode_map : Map<Int,Int>;
	var wheel_inverted : Bool;
	var textures : Array<Texture>;
	private var scene_size : {width: Int, height:Int};

	public function new(?parent) {
		super(parent);
		ImGuiDrawableBuffers.instance.initialize();

		var scene = getScene();
		ImGui.setDisplaySize(scene.width, scene.height);
		this.scene_size = {width: scene.width, height:scene.width};
		
		this.keycode_map = [
			Key.TAB => ImGuiKey.Tab,
			Key.LEFT => ImGuiKey.LeftArrow,
			Key.RIGHT => ImGuiKey.RightArrow,
			Key.UP => ImGuiKey.UpArrow,
			Key.DOWN => ImGuiKey.DownArrow,
			Key.PGUP => ImGuiKey.PageUp,
			Key.PGDOWN => ImGuiKey.PageDown,
			Key.HOME => ImGuiKey.Home,
			Key.END => ImGuiKey.End,
			Key.INSERT => ImGuiKey.Insert,
			Key.DELETE => ImGuiKey.Delete,
			Key.BACKSPACE => ImGuiKey.Backspace,
			Key.SPACE => ImGuiKey.Space,
			Key.ENTER => ImGuiKey.Enter,
			Key.ESCAPE => ImGuiKey.Escape,
			Key.NUMPAD_ENTER => ImGuiKey.KeyPadEnter,
			Key.A => ImGuiKey.A,
			Key.C => ImGuiKey.C,
			Key.V => ImGuiKey.V,
			Key.X => ImGuiKey.X,
			Key.Y => ImGuiKey.Y,
			Key.Z => ImGuiKey.Z,
		];

		this.empty_tile = h2d.Tile.fromColor(0xFFFFFF);

		scene.addEventListener(onEvent);

		this.mouse_x = scene.mouseX;
		this.mouse_y = scene.mouseY;
		this.wheel_inverted = false;
	}

	public function dispose() {
		ImGuiDrawableBuffers.instance.dispose();
	}
	
	public function update(dt:Float) {
		ImGui.setEvents(dt, this.mouse_x, this.mouse_y, this.mouse_delta, mouse_down[0], mouse_down[1]);
		ImGui.setSpecialKeyState(
			Key.isDown(Key.LSHIFT) || Key.isDown(Key.RSHIFT), 
			Key.isDown(Key.LCTRL) || Key.isDown(Key.RCTRL), 
			Key.isDown(Key.LALT) || Key.isDown(Key.RALT),
			Key.isDown(Key.LEFT_WINDOW_KEY) || Key.isDown(Key.RIGHT_WINDOW_KEY));
		this.mouse_delta = 0;

		var scene = getScene();
		if (scene.width != this.scene_size.width || scene.height != this.scene_size.height) {
			ImGui.setDisplaySize(scene.width, scene.height);
			this.scene_size = {width: scene.width, height:scene.width};
		}
	}

	private function onEvent(event: hxd.Event) {
		switch (event.kind) {
			case EMove:
				this.mouse_x = event.relX;
				this.mouse_y = event.relY;
			case EPush:
				if (event.button < 2) {
					this.mouse_down[event.button] = true;
					if (ImGui.wantCaptureMouse()) {
						event.propagate = false;
					}
				}
			case ERelease:
				if (event.button < 2) {
					this.mouse_down[event.button] = false;
					if (ImGui.wantCaptureMouse()) {
						event.propagate = false;
					}
				}
			case EWheel:
				this.mouse_delta = event.wheelDelta;
				if (!this.wheel_inverted) {
					this.mouse_delta = -this.mouse_delta;
					if (ImGui.wantCaptureMouse()) {
						event.propagate = false;
					}
				}
			case EKeyDown:
				if (this.keycode_map.exists(event.keyCode)) {
					ImGui.setKeyState(this.keycode_map[event.keyCode], true);
					if (ImGui.wantCaptureKeyboard()) {
						event.propagate = false;
					}
				}
			case EKeyUp:
				if (this.keycode_map.exists(event.keyCode)) {
					ImGui.setKeyState(this.keycode_map[event.keyCode], false);
					if (ImGui.wantCaptureKeyboard()) {
						event.propagate = false;
					}
				}
			case ETextInput:
				ImGui.addKeyChar(event.charCode);
				if (ImGui.wantCaptureKeyboard()) {
					event.propagate = false;
				}
			default:
		}
	}

	override function draw(ctx:h2d.RenderContext) {
		var vertex_buffers = ImGuiDrawableBuffers.instance.vertex_buffers;
		var index_buffers = ImGuiDrawableBuffers.instance.index_buffers;

		for (i in 0...index_buffers.length) {
			var index_buffer = index_buffers[i];
			if (ctx.beginDrawObject(this,  index_buffer.texture_id == 0 ? this.empty_tile.getTexture() : ImGuiDrawableBuffers.instance.getTexture(index_buffer.texture_id))) {
				var clip_rect = index_buffer.clip_rect;
				ctx.engine.setRenderZone(clip_rect.x, clip_rect.y, clip_rect.width, clip_rect.height);
				ctx.engine.renderIndexed(vertex_buffers[index_buffer.vertex_buffer_id], index_buffer.buffer);
			}
		}

		ctx.engine.setRenderZone();
	}
}
