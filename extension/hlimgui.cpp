#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

#include <string>

typedef struct
{
	float x;
	float y;
	float u;
	float v;
	float r;
	float g;
	float b;
	float a;
} HeapVertex;

static vclosure* s_render_function = nullptr;

void renderDrawLists(ImDrawData* draw_data)
{
	if (s_render_function == nullptr)
	{
		return;
	}

	// create the hl array passed to the hl render function
	varray* hl_cmd_list = hl_alloc_array(&hlt_dynobj, draw_data->CmdListsCount);
	vdynobj** hl_cmd_list_ptr = hl_aptr(hl_cmd_list, vdynobj*);

	for (int n = 0; n < draw_data->CmdListsCount; n++)
	{
		const ImDrawList* cmd_list = draw_data->CmdLists[n];
		const ImDrawIdx* idx_buffer = &cmd_list->IdxBuffer.front();

		// create the hl dynamic
		vdynobj* hl_cmd_list = hl_alloc_dynobj();
		hl_cmd_list_ptr[n] = hl_cmd_list;

		// create vertex buffer
		int nb_vertex = cmd_list->VtxBuffer.size();
		int vertex_buffer_size = sizeof(HeapVertex) * nb_vertex;
		HeapVertex* vertex_buffer = (HeapVertex*)hl_alloc_bytes(vertex_buffer_size);
		for (int v = 0; v < nb_vertex; v++)
		{
			auto& hl_vertex = vertex_buffer[v];
			const auto& imgui_vertex = cmd_list->VtxBuffer[v];
			hl_vertex.x = imgui_vertex.pos.x - draw_data->DisplayPos.x;
			hl_vertex.y = imgui_vertex.pos.y - draw_data->DisplayPos.y;
			hl_vertex.u = imgui_vertex.uv.x;
			hl_vertex.v = imgui_vertex.uv.y;
			convertColor(imgui_vertex.col, hl_vertex.r, hl_vertex.g, hl_vertex.b, hl_vertex.a);
		}

		// store the vertex buffer in the dynamic
		hl_dyn_setp((vdynamic*)hl_cmd_list, hl_hash_utf8("vertex_buffer"), &hlt_bytes, vertex_buffer);

		// store the vertex buffer size
		hl_dyn_seti((vdynamic*)hl_cmd_list, hl_hash_utf8("vertex_buffer_size"), &hlt_i32, vertex_buffer_size);

		// create the array for command buffer
		varray* hl_cmd_buffers = hl_alloc_array(&hlt_dynobj, cmd_list->CmdBuffer.size());
		vdynobj** hl_cmd_buffers_ptr = hl_aptr(hl_cmd_buffers, vdynobj*);

		for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.size(); cmd_i++)
		{
			const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];

			// create the hl dynamic to store the cmd buffer
			vdynobj* hl_cmd_buffer = hl_alloc_dynobj();
			hl_cmd_buffers_ptr[cmd_i] = hl_cmd_buffer;

			// store the texture id
			hl_dyn_seti((vdynamic*)hl_cmd_buffer, hl_hash_utf8("texture_id"), &hlt_i32, pcmd->TextureId);

			// create the index buffer
			int index_buffer_size = sizeof(ImDrawIdx) * pcmd->ElemCount;
			vbyte* index_buffer = hl_copy_bytes((vbyte*)idx_buffer, index_buffer_size);

			// store the index buffer
			hl_dyn_setp((vdynamic*)hl_cmd_buffer, hl_hash_utf8("index_buffer"), &hlt_bytes, index_buffer);

			// store the index buffer size
			hl_dyn_seti((vdynamic*)hl_cmd_buffer, hl_hash_utf8("index_buffer_size"), &hlt_i32, index_buffer_size);

			// store the clipping rect
			hl_dyn_seti((vdynamic*)hl_cmd_buffer, hl_hash_utf8("clip_left"), &hlt_i32, int(pcmd->ClipRect.x - draw_data->DisplayPos.x));
			hl_dyn_seti((vdynamic*)hl_cmd_buffer, hl_hash_utf8("clip_top"), &hlt_i32, int(pcmd->ClipRect.y - draw_data->DisplayPos.y));
			hl_dyn_seti((vdynamic*)hl_cmd_buffer, hl_hash_utf8("clip_width"), &hlt_i32, int(pcmd->ClipRect.z - pcmd->ClipRect.x));
			hl_dyn_seti((vdynamic*)hl_cmd_buffer, hl_hash_utf8("clip_height"), &hlt_i32, int(pcmd->ClipRect.w - pcmd->ClipRect.y));

			idx_buffer += pcmd->ElemCount;
		}

		// store the command buffer array
		hl_dyn_setp((vdynamic*)hl_cmd_list, hl_hash_utf8("draw_objects"), &hlt_array, hl_cmd_buffers);
	}

	vdynamic* param = (vdynamic*)hl_alloc_dynobj();
	hl_dyn_setp(param, hl_hash_utf8("cmd_list"), &hlt_array, hl_cmd_list);

	vdynamic* args[1];
	args[0] = param;
	hl_dyn_call(s_render_function, args, 1);
}

HL_PRIM vdynamic* HL_NAME(initialize)(vclosure* render_fn)
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();

	// set render draw function
	s_render_function = render_fn;
	hl_add_root(&s_render_function);

	// create default font texture buffer
	io.Fonts->AddFontDefault();

	unsigned char* pixels;
	int width, height;
	io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);

	vbyte* buffer = hl_copy_bytes(pixels, width*height*4);

	vdynamic* font_info = (vdynamic*)hl_alloc_dynobj();
	hl_dyn_setp(font_info, hl_hash_utf8("buffer"), &hlt_bytes, buffer);
	hl_dyn_seti(font_info, hl_hash_utf8("width"), &hlt_i32, width);
	hl_dyn_seti(font_info, hl_hash_utf8("height"), &hlt_i32, height);

	io.Fonts->ClearInputData();
	io.Fonts->ClearTexData();

	for (int key = 0; key < ImGuiKey_COUNT; key++)
	{
		io.KeyMap[key] = key;
	}

	return font_info;
}

HL_PRIM void HL_NAME(set_font_texture)(int texture_id)
{
	ImGuiIO& io = ImGui::GetIO();
	io.Fonts->SetTexID(texture_id);
}

HL_PRIM void HL_NAME(set_key_state)(int key, bool down)
{
	ImGuiIO& io = ImGui::GetIO();
	io.KeysDown[key] = down;
}

HL_PRIM void HL_NAME(set_special_key_state)(bool shift, bool ctrl, bool alt, bool super)
{
	ImGuiIO& io = ImGui::GetIO();
	io.KeyShift = shift;
	io.KeyCtrl = ctrl;
	io.KeyAlt = alt;
	io.KeySuper = super;
}

HL_PRIM void HL_NAME(add_key_char)(int c)
{
	ImGuiIO& io = ImGui::GetIO();
	io.AddInputCharacter(c);
}

HL_PRIM void HL_NAME(set_events)(float dt, float mouse_x, float mouse_y, float wheel, bool left_click, bool right_click)
{
	ImGuiIO& io = ImGui::GetIO();
	io.MousePos = ImVec2(mouse_x,mouse_y);
	io.MouseWheel = wheel;
	io.MouseDown[0] = left_click;
	io.MouseDown[1] = right_click;
}

HL_PRIM void HL_NAME(set_display_size)(int display_width, int display_height)
{
	ImGuiIO& io = ImGui::GetIO();

	io.DisplaySize = ImVec2(float(display_width), float(display_height));
}

HL_PRIM vdynamic* HL_NAME(get_style)()
{
	return getHLFromImGuiStyle(ImGui::GetStyle());
}

HL_PRIM void HL_NAME(set_style)(vdynamic* hl_style)
{
	if (hl_style != nullptr) {
		ImGui::GetStyle() = getImGuiStyleFromHL(hl_style);
	}
}

HL_PRIM void HL_NAME(new_frame)()
{
	ImGui::NewFrame();
}

HL_PRIM void HL_NAME(end_frame)()
{
	ImGui::EndFrame();
}

HL_PRIM void HL_NAME(render)()
{
	ImGui::Render();

	ImDrawData* draw_data = ImGui::GetDrawData();
	renderDrawLists(draw_data);
}

DEFINE_PRIM(_DYN, initialize, _FUN(_VOID, _DYN));
DEFINE_PRIM(_VOID, set_font_texture, _I32);
DEFINE_PRIM(_VOID, set_key_state, _I32 _BOOL);
DEFINE_PRIM(_VOID, add_key_char, _I32);
DEFINE_PRIM(_VOID, set_events, _F32 _F32 _F32 _F32 _BOOL _BOOL);
DEFINE_PRIM(_VOID, set_special_key_state, _BOOL _BOOL _BOOL _BOOL);
DEFINE_PRIM(_VOID, set_display_size, _I32 _I32);

DEFINE_PRIM(_DYN, get_style, _NO_ARG);
DEFINE_PRIM(_VOID, set_style, _DYN);
DEFINE_PRIM(_VOID, new_frame, _NO_ARG);
DEFINE_PRIM(_VOID, end_frame, _NO_ARG);
DEFINE_PRIM(_VOID, render, _NO_ARG);
