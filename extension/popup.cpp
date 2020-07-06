#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM void HL_NAME(open_popup)(vstring* str_id)
{
    ImGui::OpenPopup(unicodeToUTF8(str_id).c_str());
}

HL_PRIM bool HL_NAME(begin_popup)(vstring* str_id, ImGuiWindowFlags* flags)
{
    return ImGui::BeginPopup(convertString(str_id), convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(begin_popup_context_item)(vstring* str_id, ImGuiMouseButton* mouse_button)
{
    return ImGui::BeginPopupContextItem(convertString(str_id), convertPtr(mouse_button, 1));
}

HL_PRIM bool HL_NAME(begin_popup_context_window)(vstring* str_id, ImGuiMouseButton* mouse_button, bool* also_over_items)
{
    return ImGui::BeginPopupContextWindow(convertString(str_id), convertPtr(mouse_button, 1), convertPtr(also_over_items, true));
}

HL_PRIM bool HL_NAME(begin_popup_context_void)(vstring* str_id, ImGuiMouseButton* mouse_button)
{
    return ImGui::BeginPopupContextVoid(convertString(str_id), convertPtr(mouse_button, 1));
}

HL_PRIM bool HL_NAME(begin_popup_modal)(vstring* name, bool* p_open, ImGuiWindowFlags* flags)
{
    return ImGui::BeginPopupModal(convertString(name), p_open, convertPtr(flags, 0));
}

HL_PRIM void HL_NAME(end_popup)()
{
    ImGui::EndPopup();                                                                                             
}

HL_PRIM bool HL_NAME(open_popup_on_item_click)(vstring* str_id, ImGuiMouseButton* mouse_button)
{
    return ImGui::OpenPopupOnItemClick(convertString(str_id), convertPtr(mouse_button, 1));
}

HL_PRIM bool HL_NAME(is_popup_open)(vstring* str_id)
{
    return ImGui::IsPopupOpen(convertString(str_id));
}

HL_PRIM void HL_NAME(close_current_popup)()
{
    ImGui::CloseCurrentPopup();
}

DEFINE_PRIM(_VOID, open_popup, _STRING);
DEFINE_PRIM(_BOOL, begin_popup, _STRING _REF(_I32));
DEFINE_PRIM(_BOOL, begin_popup_context_item, _STRING _REF(_I32));
DEFINE_PRIM(_BOOL, begin_popup_context_window, _STRING _REF(_I32) _REF(_BOOL));
DEFINE_PRIM(_BOOL, begin_popup_context_void, _STRING _REF(_I32));
DEFINE_PRIM(_BOOL, begin_popup_modal, _STRING _REF(_BOOL) _REF(_I32));
DEFINE_PRIM(_VOID, end_popup, _NO_ARG);
DEFINE_PRIM(_BOOL, open_popup_on_item_click, _STRING _REF(_I32));
DEFINE_PRIM(_BOOL, is_popup_open, _STRING);
DEFINE_PRIM(_VOID, close_current_popup, _NO_ARG);
