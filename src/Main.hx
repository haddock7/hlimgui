import imgui.ImGuiDrawable;
import imgui.ImGui;

class Main extends hxd.App
{
    var drawable:ImGuiDrawable;

    override function init() 
    {
        this.drawable = new ImGuiDrawable(this.s2d);
    }

    override function update(dt:Float)
    {
        drawable.update(dt);

        ImGui.newFrame();

        ImGui.showDemoWindow();

        ImGui.render();
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