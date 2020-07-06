#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM bool HL_NAME(selectable)(vstring* label, bool* selected, ImGuiSelectableFlags* flags, vdynamic* size)
{
    return ImGui::Selectable(convertString(label), convertPtr(selected, false), convertPtr(flags, 0), getImVec2(size));
}

HL_PRIM bool HL_NAME(selectable2)(vstring* label, bool* p_selected, ImGuiSelectableFlags* flags, vdynamic* size)
{
    return ImGui::Selectable(convertString(label), p_selected, convertPtr(flags, 0), getImVec2(size));
}

DEFINE_PRIM(_BOOL, selectable, _STRING _REF(_BOOL) _REF(_I32) _DYN);
DEFINE_PRIM(_BOOL, selectable2, _STRING _REF(_BOOL) _REF(_I32) _DYN);
