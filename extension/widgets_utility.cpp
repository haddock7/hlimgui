#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM bool HL_NAME(is_item_hovered)(ImGuiHoveredFlags* flags)
{
    return ImGui::IsItemHovered(convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(is_item_active)()
{
    return ImGui::IsItemActive();
}

HL_PRIM bool HL_NAME(is_item_focused)()
{
    return ImGui::IsItemFocused();
}

HL_PRIM bool HL_NAME(is_item_clicked)(ImGuiMouseButton* mouse_button)
{
    return ImGui::IsItemClicked(convertPtr(mouse_button, 0));
}

HL_PRIM bool HL_NAME(is_item_visible)()
{
    return ImGui::IsItemVisible();
}

HL_PRIM bool HL_NAME(is_item_edited)()
{
    return ImGui::IsItemEdited();
}

HL_PRIM bool HL_NAME(is_item_activated)()
{
    return ImGui::IsItemActivated();
}

HL_PRIM bool HL_NAME(is_item_deactivated)()
{
    return ImGui::IsItemDeactivated();
}

HL_PRIM bool HL_NAME(is_item_deactivated_after_edit)()
{
    return ImGui::IsItemDeactivatedAfterEdit();
}

HL_PRIM bool HL_NAME(is_item_toggled_open)()
{
    return ImGui::IsItemToggledOpen();
}

HL_PRIM bool HL_NAME(is_any_item_hovered)()
{
    return ImGui::IsAnyItemHovered();
}

HL_PRIM bool HL_NAME(is_any_item_active)()
{
    return ImGui::IsAnyItemActive();
}

HL_PRIM bool HL_NAME(is_any_item_focused)()
{
    return ImGui::IsAnyItemFocused();
}

HL_PRIM vdynamic* HL_NAME(get_item_rect_min)()
{
    return getHLFromImVec2(ImGui::GetItemRectMin());
}

HL_PRIM vdynamic* HL_NAME(get_item_rect_max)()
{
    return getHLFromImVec2(ImGui::GetItemRectMax());
}

HL_PRIM vdynamic* HL_NAME(get_item_rect_size)()
{
    return getHLFromImVec2(ImGui::GetItemRectSize());
}

HL_PRIM void HL_NAME(set_item_allow_overlap)()
{
    ImGui::SetItemAllowOverlap();
}

DEFINE_PRIM(_BOOL, is_item_hovered, _REF(_I32));
DEFINE_PRIM(_BOOL, is_item_active, _NO_ARG);
DEFINE_PRIM(_BOOL, is_item_focused, _NO_ARG);
DEFINE_PRIM(_BOOL, is_item_clicked, _REF(_I32));
DEFINE_PRIM(_BOOL, is_item_visible, _NO_ARG);
DEFINE_PRIM(_BOOL, is_item_edited, _NO_ARG);
DEFINE_PRIM(_BOOL, is_item_activated, _NO_ARG);
DEFINE_PRIM(_BOOL, is_item_deactivated, _NO_ARG);
DEFINE_PRIM(_BOOL, is_item_deactivated_after_edit, _NO_ARG);
DEFINE_PRIM(_BOOL, is_item_toggled_open, _NO_ARG);
DEFINE_PRIM(_BOOL, is_any_item_hovered, _NO_ARG);
DEFINE_PRIM(_BOOL, is_any_item_active, _NO_ARG);
DEFINE_PRIM(_BOOL, is_any_item_focused, _NO_ARG);
DEFINE_PRIM(_DYN, get_item_rect_min, _NO_ARG);
DEFINE_PRIM(_DYN, get_item_rect_max, _NO_ARG);
DEFINE_PRIM(_DYN, get_item_rect_size, _NO_ARG);
DEFINE_PRIM(_VOID, set_item_allow_overlap, _NO_ARG);
