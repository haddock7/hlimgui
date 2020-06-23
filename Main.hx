import imgui.ImGuiDrawable;
import imgui.ImGui;

class Main extends hxd.App
{
    var drawable:ImGuiDrawable;

    override function init() 
    {
        this.drawable = new ImGuiDrawable(this.s2d);

        trace('toto');
    }

    override function update(dt:Float)
    {
        if (this.drawable != null) {
            drawable.update(dt);

            ImGui.newFrame();

            ImGui.styleColorsLight();
            ImGui.begin('Toto');
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