#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include <vector>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM bool HL_NAME(is_mouse_down)(ImGuiMouseButton button)
{
    return ImGui::IsMouseDown(button);
}

HL_PRIM bool HL_NAME(is_mouse_clicked)(ImGuiMouseButton button, bool* repeat)
{
    return ImGui::IsMouseClicked(button, convertPtr(repeat, false));
}

HL_PRIM bool HL_NAME(is_mouse_released)(ImGuiMouseButton button)
{
    return ImGui::IsMouseReleased(button);
}

HL_PRIM bool HL_NAME(is_mouse_double_clicked)(ImGuiMouseButton button)
{
    return ImGui::IsMouseDoubleClicked(button);
}

HL_PRIM bool HL_NAME(is_mouse_hovering_rect)(vdynamic* r_min, vdynamic* r_max, bool* clip)
{
    return ImGui::IsMouseHoveringRect(getImVec2(r_min), getImVec2(r_max), convertPtr(clip, true));
}

HL_PRIM bool HL_NAME(is_mouse_pos_valid)(vdynamic* mouse_pos)
{
    ImVec2 vec;
    ImVec2* vec_ptr;
    if (mouse_pos != nullptr)
    {
        vec = getImVec2(mouse_pos);
        vec_ptr = &vec;
    }
    else
    {
        vec_ptr = NULL;
    }
    return ImGui::IsMousePosValid(vec_ptr);
}

HL_PRIM bool HL_NAME(is_any_mouse_down)()
{
    return ImGui::IsAnyMouseDown();
}

HL_PRIM vdynamic* HL_NAME(get_mouse_pos)()
{
    return getHLFromImVec2(ImGui::GetMousePos());
}

HL_PRIM vdynamic* HL_NAME(get_mouse_pos_on_opening_current_popup)()
{
    return getHLFromImVec2(ImGui::GetMousePosOnOpeningCurrentPopup());
}

HL_PRIM bool HL_NAME(is_mouse_dragging)(ImGuiMouseButton button, float* lock_threshold)
{
    return ImGui::IsMouseDragging(button, convertPtr(lock_threshold, -1.0f));
}

HL_PRIM vdynamic* HL_NAME(get_mouse_drag_delta)(ImGuiMouseButton* button, float* lock_threshold)
{
    return getHLFromImVec2(ImGui::GetMouseDragDelta(convertPtr(button, 0), convertPtr(lock_threshold, -1.0f)));
}

HL_PRIM void HL_NAME(reset_mouse_drag_delta)(ImGuiMouseButton* button)
{
    ImGui::ResetMouseDragDelta(convertPtr(button, 0));
}

HL_PRIM ImGuiMouseCursor HL_NAME(get_mouse_cursor)()
{
    return ImGui::GetMouseCursor();
}

HL_PRIM void HL_NAME(set_mouse_cursor)(ImGuiMouseCursor cursor_type)
{
    ImGui::SetMouseCursor(cursor_type);
}

HL_PRIM void HL_NAME(capture_mouse_from_app)(bool* want_capture_mouse_value)
{
    ImGui::CaptureMouseFromApp(convertPtr(want_capture_mouse_value, true));
}

DEFINE_PRIM(_BOOL, is_mouse_down, _I32);
DEFINE_PRIM(_BOOL, is_mouse_clicked, _I32 _REF(_BOOL));
DEFINE_PRIM(_BOOL, is_mouse_released, _I32);
DEFINE_PRIM(_BOOL, is_mouse_double_clicked, _I32);
DEFINE_PRIM(_BOOL, is_mouse_hovering_rect, _DYN _DYN _REF(_BOOL));
DEFINE_PRIM(_BOOL, is_mouse_pos_valid, _DYN);
DEFINE_PRIM(_BOOL, is_any_mouse_down, _NO_ARG);
DEFINE_PRIM(_DYN, get_mouse_pos, _NO_ARG);
DEFINE_PRIM(_DYN, get_mouse_pos_on_opening_current_popup, _NO_ARG);
DEFINE_PRIM(_BOOL, is_mouse_dragging, _I32 _REF(_F32));
DEFINE_PRIM(_DYN, get_mouse_drag_delta, _REF(_I32) _REF(_F32));
DEFINE_PRIM(_VOID, reset_mouse_drag_delta, _REF(_I32));
DEFINE_PRIM(_I32, get_mouse_cursor, _NO_ARG);
DEFINE_PRIM(_VOID, set_mouse_cursor, _I32);
DEFINE_PRIM(_VOID, capture_mouse_from_app, _REF(_BOOL));
