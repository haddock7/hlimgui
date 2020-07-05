#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "struct.h"
#include "convert.h"

HL_PRIM bool HL_NAME(slider_float)(vstring* label, varray* v, float v_min, float v_max, vstring* format, float* power)
{
    if (v->size < 1 || v->size > 4)
    {
        hl_error("v parameter size must be between 1 and 4");
    }

    switch (v->size)
    {
        case 1:
            return ImGui::SliderFloat(convertString(label), hl_aptr(v,float), v_min, v_max, convertString(format), convertPtr(power, 1.0f));

        case 2:
            return ImGui::SliderFloat2(convertString(label), hl_aptr(v,float), v_min, v_max, convertString(format), convertPtr(power, 1.0f));

        case 3:
            return ImGui::SliderFloat3(convertString(label), hl_aptr(v,float), v_min, v_max, convertString(format), convertPtr(power, 1.0f));

        default:
            return ImGui::SliderFloat4(convertString(label), hl_aptr(v,float), v_min, v_max, convertString(format), convertPtr(power, 1.0f));
    }
}

HL_PRIM bool HL_NAME(slider_angle)(vstring* label, float* v_rad, float* v_degrees_minf, float* v_degrees_max, vstring* format)
{
    return ImGui::SliderAngle(convertString(label), v_rad, convertPtr(v_degrees_minf, -360.0f), convertPtr(v_degrees_max, +360.0f), convertString(format));
}

HL_PRIM bool HL_NAME(slider_int)(vstring* label, varray* v, int v_min, int v_max, vstring* format)
{
    if (v->size < 1 || v->size > 4)
    {
        hl_error("v parameter size must be between 1 and 4");
    }

    switch (v->size)
    {
        case 1:
            return ImGui::SliderInt(convertString(label), hl_aptr(v,int), v_min, v_max, convertString(format));

        case 2:
            return ImGui::SliderInt2(convertString(label), hl_aptr(v,int), v_min, v_max, convertString(format));

        case 3:
            return ImGui::SliderInt3(convertString(label), hl_aptr(v,int), v_min, v_max, convertString(format));

        default:
            return ImGui::SliderInt4(convertString(label), hl_aptr(v,int), v_min, v_max, convertString(format));
    }
}

HL_PRIM bool HL_NAME(v_slider_float)(vstring* label, vdynamic* size, float* v, float v_min, float v_max, vstring* format, float* power)
{
    return ImGui::VSliderFloat(convertString(label), getImVec2(size), v, v_min, v_max, convertString(format), convertPtr(power, 1.0f));
}

HL_PRIM bool HL_NAME(v_slider_int)(vstring* label, vdynamic* size, int* v, int v_min, int v_max, vstring* format)
{
    return ImGui::VSliderInt(convertString(label), getImVec2(size), v, v_min, v_max, convertString(format));
}

DEFINE_PRIM(_BOOL, slider_float, _STRING _ARR _F32 _F32 _STRING _REF(_F32));
DEFINE_PRIM(_BOOL, slider_angle, _STRING _REF(_F32) _REF(_F32) _REF(_F32) _STRING);
DEFINE_PRIM(_BOOL, slider_int, _STRING _ARR _I32 _I32 _STRING);
DEFINE_PRIM(_BOOL, v_slider_float, _STRING _DYN _REF(_F32) _F32 _F32 _STRING _REF(_F32));
DEFINE_PRIM(_BOOL, v_slider_int, _STRING _DYN _REF(_I32) _I32 _I32 _STRING);