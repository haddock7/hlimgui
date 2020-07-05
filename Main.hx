import imgui.ImGuiDrawable;
import imgui.ImGui;

class Main extends hxd.App
{
    var drawable:ImGuiDrawable;
    var drag_values: hl.NativeArray<Int>;
    var vslider_value : Int = 0;
    var input_int = new hl.NativeArray<Int>(2);
    var input_text_buffer = new hl.Bytes(128);

    override function init() 
    {
        this.drawable = new ImGuiDrawable(this.s2d);
        this.drag_values = new hl.NativeArray<Int>(2);
        this.drag_values[0] = 1;
        this.drag_values[1] = 2;

        this.input_int[0] = 0;
        this.input_int[1] = 0;
        this.input_text_buffer[0] = 0;
    }

    override function update(dt:Float)
    {
        if (this.drawable != null) {
            drawable.update(dt);

            ImGui.newFrame();

            ImGui.styleColorsLight();
            ImGui.begin('Toto');

            ImGui.inputInt2('Input', this.input_int);
            if (ImGui.inputText('Text', this.input_text_buffer, 128)) {
                var st = @:privateAccess String.fromUTF8(this.input_text_buffer);
                trace(st);
            }

            ImGui.end();

            ImGui.render();
        }
    }

    override function onResize()
    {
        ImGui.setDisplaySize(this.s2d.width, this.s2d.height);
    }

    static function main() 
    {
        new Main();
    }
}