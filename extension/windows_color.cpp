#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM bool HL_NAME(color_edit3)(vstring* label, varray* col, ImGuiColorEditFlags* flags)
{
    assertArraySize(col, 3);
    return ImGui::ColorEdit3(convertString(label), hl_aptr(col,float), convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(color_edit4)(vstring* label, varray* col, ImGuiColorEditFlags* flags)
{
    assertArraySize(col, 4);
    return ImGui::ColorEdit4(convertString(label), hl_aptr(col,float), convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(color_picker3)(vstring* label, varray* col, ImGuiColorEditFlags* flags)
{
    assertArraySize(col, 3);
    return ImGui::ColorPicker3(convertString(label), hl_aptr(col,float), convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(color_picker4)(vstring* label, varray* col, ImGuiColorEditFlags* flags, const float* ref_col)
{
    assertArraySize(col, 4);
    return ImGui::ColorPicker4(convertString(label), hl_aptr(col,float), convertPtr(flags, 0), ref_col);
}

HL_PRIM bool HL_NAME(color_button)(vstring* desc_id, vdynamic* col, ImGuiColorEditFlags* flags, vdynamic* size)
{
    return ImGui::ColorButton(convertString(desc_id), getImVec4(col), convertPtr(flags, 0), getImVec2(size));
}

HL_PRIM void HL_NAME(set_color_edit_options)(ImGuiColorEditFlags flags)
{
    ImGui::SetColorEditOptions(flags);
}

DEFINE_PRIM(_BOOL, color_edit3, _STRING _ARR _REF(_I32));
DEFINE_PRIM(_BOOL, color_edit4, _STRING _ARR _REF(_I32));
DEFINE_PRIM(_BOOL, color_picker3, _STRING _ARR _REF(_I32));
DEFINE_PRIM(_BOOL, color_picker4, _STRING _ARR _REF(_I32) _REF(_F32));
DEFINE_PRIM(_BOOL, color_button, _STRING _DYN _REF(_I32) _DYN);
DEFINE_PRIM(_VOID, set_color_edit_options, _I32);
