#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM bool HL_NAME(begin_menu_bar)()
{
    return ImGui::BeginMenuBar();
}

HL_PRIM void HL_NAME(end_menu_bar)()
{
    ImGui::EndMenuBar();
}

HL_PRIM bool HL_NAME(begin_main_menu_bar)()
{
    return ImGui::BeginMainMenuBar();
}

HL_PRIM void HL_NAME(end_main_menu_bar)()
{
    ImGui::EndMainMenuBar();
}

HL_PRIM bool HL_NAME(begin_menu)(vstring* label, bool* enabled)
{
    return ImGui::BeginMenu(convertString(label), convertPtr(enabled, false));
}

HL_PRIM void HL_NAME(end_menu)()
{
    ImGui::EndMenu();
}

HL_PRIM bool HL_NAME(menu_item)(vstring* label, vstring* shortcut, bool* selected, bool* enabled)
{
    return ImGui::MenuItem(convertString(label), convertString(shortcut), convertPtr(selected, false), convertPtr(enabled, true));
}

HL_PRIM bool HL_NAME(menu_item2)(vstring* label, vstring* shortcut, bool* p_selected, bool* enabled)
{
    return ImGui::MenuItem(convertString(label), convertString(shortcut), p_selected, convertPtr(enabled, true));
}

DEFINE_PRIM(_BOOL, begin_menu_bar, _NO_ARG);
DEFINE_PRIM(_VOID, end_menu_bar, _NO_ARG);
DEFINE_PRIM(_BOOL, begin_main_menu_bar, _NO_ARG);
DEFINE_PRIM(_VOID, end_main_menu_bar, _NO_ARG);
DEFINE_PRIM(_BOOL, begin_menu, _STRING _REF(_BOOL));
DEFINE_PRIM(_VOID, end_menu, _NO_ARG);
DEFINE_PRIM(_BOOL, menu_item, _STRING _STRING _REF(_BOOL) _REF(_BOOL));
DEFINE_PRIM(_BOOL, menu_item2, _STRING _STRING _REF(_BOOL) _REF(_BOOL));
