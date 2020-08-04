# Heaps/HashLink native binding for [Dear ImGui](https://github.com/ocornut/imgui)

## Build & Install
The native extension needs first to be built.

```
cd extension
mkdir build
cd build

cmake ..
cmake --build .
```
This commands build a the target `hdll` file, and copy it to the root of the project.

To add this library to your project, you need to include these files:

- The previously compiled `hlimgui.hdll` file.
- `imgui/ImGuiDrawable.hx`: this class derives from the standard Heaps `Drawable` class and contains and displays all ImGui widgets.
- `imgui/ImGui.hx`: interface to the native extension.

See `Main.hx` to see how to implement this library.

## Supported ImGui features
Most of the ImGui functionalities are supported and binded. Look at  [https://github.com/ocornut/imgui](https://github.com/ocornut/imgui) to get documentation on how ImGui works and exposed functions.

Here is a list of unsupported features and changes:

- Custom fonts aren't implemented.
- As Haxe doesn't function overloading, so if two original functions have the same name, the second one in Haxe has a suffix `2` to disguish it. For example:
```haxe
public static function treeNode(label : String) : Bool {return false;}
public static function treeNode2(str_id : String, label : String) : Bool {return false;}
```
- ImGui has several functions which takes a variable number of parameters in order to format strings. This feature isn't supported in Haxe, so all string formatting must be done in Haxe before passing it to ImGui.

- `InputText` function takes a byte buffer as parameter. This needs to be converted to a string like this example:
```haxe
var input_text_buffer = new hl.Bytes(128);
if (ImGui.inputText('Text', input_text_buffer, 128)) {
    var st = @:privateAccess String.fromUTF8(input_text_buffer);
    trace(st);
}
```
- The function `setIniFilename` doesn't exist in ImGui, it has been added to modify the filename of the default ini file saved by ImGui (pass null to turn off this feature).

## Bugs
I you find bugs, please report them on the GitHub project page. Most of the binded functions have been tested, but as it's a new library some bugs might remain.

## Thanks
I would like to thanks [Aidan63](https://github.com/Aidan63/linc_imgui) for their Haxe/cpp binding. I have borrowed all the structure declaration code which remains the same between the two bindings.
