#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM bool HL_NAME(begin_tab_bar)(vstring* str_id, ImGuiTabBarFlags* flags)
{
    return ImGui::BeginTabBar(convertString(str_id), convertPtr(flags, 0));
}

HL_PRIM void HL_NAME(end_tab_bar)()
{
    ImGui::EndTabBar();
}

HL_PRIM bool HL_NAME(begin_tab_item)(vstring* label, bool* p_open, ImGuiTabItemFlags* flags)
{
    return ImGui::BeginTabItem(convertString(label), p_open, convertPtr(flags, 0));
}

HL_PRIM void HL_NAME(end_tab_item)()
{
    ImGui::EndTabItem();
}

HL_PRIM void HL_NAME(set_tab_item_closed)(vstring* tab_or_docked_window_label)
{
    ImGui::SetTabItemClosed(convertString(tab_or_docked_window_label));
}

DEFINE_PRIM(_BOOL, begin_tab_bar, _STRING _REF(_I32));
DEFINE_PRIM(_VOID, end_tab_bar, _NO_ARG);
DEFINE_PRIM(_BOOL, begin_tab_item, _STRING _REF(_BOOL) _REF(_I32));
DEFINE_PRIM(_VOID, end_tab_item, _NO_ARG);
DEFINE_PRIM(_VOID, set_tab_item_closed, _STRING);
