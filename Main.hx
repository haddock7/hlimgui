import imgui.ImGuiDrawable;
import imgui.ImGui;

class Main extends hxd.App
{
    var drawable:ImGuiDrawable;
    var drag_values: hl.NativeArray<Int>;
    var vslider_value : Int = 0;
    var input_int = new hl.NativeArray<Int>(2);
    var input_text_buffer = new hl.Bytes(128);
    var color : Int = 0;

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

            var rgba = new hl.NativeArray<Single>(4);
            rgba[0] = (this.color & 0xFF)/255;
            rgba[1] = ((this.color >> 8) & 0xFF)/255;
            rgba[2] = ((this.color >> 16) & 0xFF)/255;
            rgba[3] = (this.color >> 24)/255;
    
            if (ImGui.colorEdit4('Color', rgba)) {
                this.color = 
                    Math.round(rgba[0]*255) + 
                    (Math.round(rgba[1]*255) << 8) + 
                    (Math.round(rgba[2]*255) << 16) + 
                    (Math.round(rgba[3]*255) << 24);
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