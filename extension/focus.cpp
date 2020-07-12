#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM void HL_NAME(set_item_default_focus)()
{
    ImGui::SetItemDefaultFocus();
}

HL_PRIM void HL_NAME(set_keyboard_focus_here)(int* offset)
{
    ImGui::SetKeyboardFocusHere(convertPtr(offset, 0));
}

DEFINE_PRIM(_VOID, set_item_default_focus, _NO_ARG);
DEFINE_PRIM(_VOID, set_keyboard_focus_here, _REF(_I32));
