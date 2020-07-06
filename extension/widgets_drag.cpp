#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM bool HL_NAME(drag_float)(vstring* label, varray* v, float* v_speed, float* v_min, float* v_max, vstring* format, float* power)
{
    assertArraySizeRange(v, 1, 4);

    switch (v->size)
    {
        case 1:
            return ImGui::DragFloat(convertString(label), hl_aptr(v,float), convertPtr(v_speed, 1.0f), convertPtr(v_min, 0.0f), convertPtr(v_max, 0.0f), convertString(format), convertPtr(power, 1.0f));

        case 2:
            return ImGui::DragFloat2(convertString(label), hl_aptr(v,float), convertPtr(v_speed, 1.0f), convertPtr(v_min, 0.0f), convertPtr(v_max, 0.0f), convertString(format), convertPtr(power, 1.0f));

        case 3:
            return ImGui::DragFloat3(convertString(label), hl_aptr(v,float), convertPtr(v_speed, 1.0f), convertPtr(v_min, 0.0f), convertPtr(v_max, 0.0f), convertString(format), convertPtr(power, 1.0f));

        default:
            return ImGui::DragFloat4(convertString(label), hl_aptr(v,float), convertPtr(v_speed, 1.0f), convertPtr(v_min, 0.0f), convertPtr(v_max, 0.0f), convertString(format), convertPtr(power, 1.0f));
    }
}

HL_PRIM bool HL_NAME(drag_float_range2)(vstring* label, float* v_current_min, float* v_current_max, float* v_speed, float* v_min, float* v_max, vstring* format, vstring* format_max, float* power)
{
    return ImGui::DragFloatRange2(convertString(label), v_current_min, v_current_max, convertPtr(v_speed, 1.0f), convertPtr(v_min, 0.0f), convertPtr(v_max, 0.0f), convertString(format), convertString(format_max), convertPtr(power, 1.0f));
}

HL_PRIM bool HL_NAME(drag_int)(vstring* label, varray* v, float* v_speed, int* v_min, int* v_max, vstring* format)
{
    assertArraySizeRange(v, 1, 4);

    switch (v->size)
    {
        case 1:
            return ImGui::DragInt(convertString(label), hl_aptr(v,int), convertPtr(v_speed, 1.0f), convertPtr(v_min, 0), convertPtr(v_max, 0), convertString(format));

        case 2:
            return ImGui::DragInt2(convertString(label), hl_aptr(v,int), convertPtr(v_speed, 1.0f), convertPtr(v_min, 0), convertPtr(v_max, 0), convertString(format));

        case 3:
            return ImGui::DragInt3(convertString(label), hl_aptr(v,int), convertPtr(v_speed, 1.0f), convertPtr(v_min, 0), convertPtr(v_max, 0), convertString(format));

        default:
            return ImGui::DragInt4(convertString(label), hl_aptr(v,int), convertPtr(v_speed, 1.0f), convertPtr(v_min, 0), convertPtr(v_max, 0), convertString(format));
    }
}

HL_PRIM bool HL_NAME(drag_int_range2)(vstring* label, int* v_current_min, int* v_current_max, float* v_speed, int* v_min, int* v_max, vstring* format, vstring* format_max)
{
    return ImGui::DragIntRange2(convertString(label), v_current_min, v_current_max, convertPtr(v_speed, 1.0f), convertPtr(v_min, 0), convertPtr(v_max, 0), convertString(format), convertString(format_max));
}

DEFINE_PRIM(_BOOL, drag_float, _STRING _ARR _REF(_F32) _REF(_F32) _REF(_F32) _STRING _REF(_F32));
DEFINE_PRIM(_BOOL, drag_float_range2, _STRING _REF(_F32) _REF(_F32) _REF(_F32) _REF(_F32) _REF(_F32) _STRING _STRING _REF(_F32));
DEFINE_PRIM(_BOOL, drag_int, _STRING _ARR _REF(_F32) _REF(_F32) _REF(_F32) _STRING);
DEFINE_PRIM(_BOOL, drag_int_range2, _STRING _REF(_I32) _REF(_I32) _REF(_F32) _REF(_F32) _REF(_F32) _STRING _STRING);
