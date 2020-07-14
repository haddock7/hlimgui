#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include <vector>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM vdynamic* HL_NAME(color_convert_u32_to_float4)(ImU32 in)
{
    return getHLFromImVec4(ImGui::ColorConvertU32ToFloat4(in));
}

HL_PRIM ImU32 HL_NAME(color_convert_float4_to_u32)(vdynamic* in)
{
    return ImGui::ColorConvertFloat4ToU32(getImVec4(in));
}

HL_PRIM void HL_NAME(color_convert_rgbto_hsv)(float r, float g, float b, float* out_h, float* out_s, float* out_v)
{
    ImGui::ColorConvertRGBtoHSV(r, g, b, *out_h, *out_s, *out_v);
}

HL_PRIM void HL_NAME(color_convert_hsvto_rgb)(float h, float s, float v, float* out_r, float* out_g, float* out_b)
{
    ImGui::ColorConvertHSVtoRGB(h, s, v, *out_r, *out_g, *out_b);
}

DEFINE_PRIM(_DYN, color_convert_u32_to_float4, _I32);
DEFINE_PRIM(_I32, color_convert_float4_to_u32, _DYN);
DEFINE_PRIM(_VOID, color_convert_rgbto_hsv, _F32 _F32 _F32 _REF(_F32) _REF(_F32) _REF(_F32));
DEFINE_PRIM(_VOID, color_convert_hsvto_rgb, _F32 _F32 _F32 _REF(_F32) _REF(_F32) _REF(_F32));
