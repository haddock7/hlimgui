#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include <vector>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM void HL_NAME(plot_lines)(vstring* label, varray* values, int* values_offset, vstring* overlay_text, float* scale_min, float* scale_max, vdynamic* graph_size)
{
    ImGui::PlotLines(convertString(label), hl_aptr(values, float), values->size, convertPtr(values_offset, 0), convertString(overlay_text), convertPtr(scale_min, FLT_MAX), convertPtr(scale_max, FLT_MAX), getImVec2(graph_size));
}

HL_PRIM void HL_NAME(plot_histogram)(vstring* label, varray* values, int* values_offset, vstring* overlay_text, float* scale_min, float* scale_max, vdynamic* graph_size)
{
    ImGui::PlotHistogram(convertString(label), hl_aptr(values, float), values->size, convertPtr(values_offset, 0), convertString(overlay_text), convertPtr(scale_min, FLT_MAX), convertPtr(scale_max, FLT_MAX), getImVec2(graph_size));
}

DEFINE_PRIM(_VOID, plot_lines, _STRING _ARR _REF(_I32) _STRING _REF(_F32) _REF(_F32) _DYN);
DEFINE_PRIM(_VOID, plot_histogram, _STRING _ARR _REF(_I32) _STRING _REF(_F32) _REF(_F32) _DYN);
