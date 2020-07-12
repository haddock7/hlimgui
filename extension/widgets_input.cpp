#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM bool HL_NAME(input_text)(vstring* label, vbyte* buf, int buf_size, ImGuiInputTextFlags* flags)
{
    return ImGui::InputText(convertString(label), (char*)buf, buf_size, convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(input_text_multiline)(vstring* label, vbyte* buf, int buf_size, vdynamic* size, ImGuiInputTextFlags* flags)
{
    return ImGui::InputTextMultiline(convertString(label), (char*)buf, buf_size, getImVec2(size), convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(input_text_with_hint)(vstring* label, vstring* hint, vbyte* buf, int buf_size, ImGuiInputTextFlags* flags)
{
    return ImGui::InputTextWithHint(convertString(label), convertString(hint), (char*)buf, buf_size, convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(input_float)(vstring* label, float* v, float* step, float* step_fast, vstring* format, ImGuiInputTextFlags* flags)
{
    return ImGui::InputFloat(convertString(label), v, convertPtr(step, 0.0f), convertPtr(step_fast, 0.0f), convertString(format), convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(input_float2)(vstring* label, varray* v, vstring* format, ImGuiInputTextFlags* flags)
{
    assertArraySize(v, 2);
    return ImGui::InputFloat2(convertString(label), hl_aptr(v,float), convertString(format), convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(input_float3)(vstring* label, varray* v, vstring* format, ImGuiInputTextFlags* flags)
{
    assertArraySize(v, 3);
    return ImGui::InputFloat3(convertString(label), hl_aptr(v,float), convertString(format), convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(input_float4)(vstring* label, varray* v, vstring* format, ImGuiInputTextFlags* flags)
{
    assertArraySize(v, 4);
    return ImGui::InputFloat4(convertString(label), hl_aptr(v,float), convertString(format), convertPtr(flags, 0));
}


HL_PRIM bool HL_NAME(input_int)(vstring* label, int* v, int* step, int* step_fast, ImGuiInputTextFlags* flags)
{
    return ImGui::InputInt(convertString(label), v, convertPtr(step, 1), convertPtr(step_fast, 100), convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(input_int2)(vstring* label, varray* v, ImGuiInputTextFlags* flags)
{
    assertArraySize(v, 2);
    return ImGui::InputInt2(convertString(label), hl_aptr(v,int), convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(input_int3)(vstring* label, varray* v, ImGuiInputTextFlags* flags)
{
    assertArraySize(v, 3);
    return ImGui::InputInt3(convertString(label), hl_aptr(v,int), convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(input_int4)(vstring* label, varray* v, ImGuiInputTextFlags* flags)
{
    assertArraySize(v, 4);
    return ImGui::InputInt4(convertString(label), hl_aptr(v,int), convertPtr(flags, 0));
}


HL_PRIM bool HL_NAME(input_double)(vstring* label, double* v, double* step, double* step_fast, vstring* format, ImGuiInputTextFlags* flags)
{
    return ImGui::InputDouble(convertString(label), v, convertPtr(step, 0.0), convertPtr(step_fast, 0.0), convertString(format), convertPtr(flags, 0));
}

DEFINE_PRIM(_BOOL, input_text, _STRING _BYTES _I32 _REF(_I32));
DEFINE_PRIM(_BOOL, input_text_multiline, _STRING _BYTES _I32 _DYN _REF(_I32));
DEFINE_PRIM(_BOOL, input_text_with_hint, _STRING _STRING _BYTES _I32 _REF(_I32));
DEFINE_PRIM(_BOOL, input_float, _STRING _REF(_F32) _REF(_F32) _REF(_F32) _STRING _REF(_I32));
DEFINE_PRIM(_BOOL, input_float2, _STRING _ARR _STRING _REF(_I32));
DEFINE_PRIM(_BOOL, input_float3, _STRING _ARR _STRING _REF(_I32));
DEFINE_PRIM(_BOOL, input_float4, _STRING _ARR _STRING _REF(_I32));
DEFINE_PRIM(_BOOL, input_int, _STRING _REF(_I32) _REF(_I32) _REF(_I32) _REF(_I32));
DEFINE_PRIM(_BOOL, input_int2, _STRING _ARR _REF(_I32));
DEFINE_PRIM(_BOOL, input_int3, _STRING _ARR _REF(_I32));
DEFINE_PRIM(_BOOL, input_int4, _STRING _ARR _REF(_I32));
DEFINE_PRIM(_BOOL, input_double, _STRING _REF(_F64) _REF(_F64) _REF(_F64) _STRING _REF(_I32));
