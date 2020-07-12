#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM void HL_NAME(value_bool)(vstring* prefix, bool b)
{
    ImGui::Value(convertString(prefix), b);
}

HL_PRIM void HL_NAME(value_int)(vstring* prefix, int v)
{
    ImGui::Value(convertString(prefix), v);
}

HL_PRIM void HL_NAME(value_single)(vstring* prefix, float v, vstring* float_format)
{
    ImGui::Value(convertString(prefix), v, convertString(float_format));
}

DEFINE_PRIM(_VOID, value_bool, _STRING _BOOL);
DEFINE_PRIM(_VOID, value_int, _STRING _I32);
DEFINE_PRIM(_VOID, value_single, _STRING _F32 _STRING);
