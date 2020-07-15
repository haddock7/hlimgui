#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include <vector>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM int HL_NAME(get_key_index)(ImGuiKey imgui_key)
{
    return ImGui::GetKeyIndex(imgui_key);
}

HL_PRIM bool HL_NAME(is_key_down)(int user_key_index)
{
    return ImGui::IsKeyDown(user_key_index);
}

HL_PRIM bool HL_NAME(is_key_pressed)(int user_key_index, bool* repeat)
{
    return ImGui::IsKeyPressed(user_key_index, convertPtr(repeat, true));
}

HL_PRIM bool HL_NAME(is_key_released)(int user_key_index)
{
    return ImGui::IsKeyReleased(user_key_index);
}

HL_PRIM int HL_NAME(get_key_pressed_amount)(int key_index, float repeat_delay, float rate)
{
    return ImGui::GetKeyPressedAmount(key_index, repeat_delay, rate);
}

HL_PRIM void HL_NAME(capture_keyboard_from_app)(bool* want_capture_keyboard_value)
{
    ImGui::CaptureKeyboardFromApp(convertPtr(want_capture_keyboard_value, true));
}

DEFINE_PRIM(_I32, get_key_index, _I32);
DEFINE_PRIM(_BOOL, is_key_down, _I32);
DEFINE_PRIM(_BOOL, is_key_pressed, _I32 _REF(_BOOL));
DEFINE_PRIM(_BOOL, is_key_released, _I32);
DEFINE_PRIM(_I32, get_key_pressed_amount, _I32 _F32 _F32);
DEFINE_PRIM(_VOID, capture_keyboard_from_app, _REF(_BOOL));
