#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include <vector>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM bool HL_NAME(is_rect_visible)(vdynamic* size)
{
    return ImGui::IsRectVisible(getImVec2(size));
}

HL_PRIM bool HL_NAME(is_rect_visible2)(vdynamic* rect_min, vdynamic* rect_max)
{
    return ImGui::IsRectVisible(getImVec2(rect_min), getImVec2(rect_max));
}

HL_PRIM double HL_NAME(get_time)()
{
    return ImGui::GetTime();
}

HL_PRIM int HL_NAME(get_frame_count)()
{
    return ImGui::GetFrameCount();
}

HL_PRIM vbyte* HL_NAME(get_style_color_name)(ImGuiCol idx)
{
    return getVByteFromCStr(ImGui::GetStyleColorName(idx));
}

HL_PRIM void HL_NAME(calc_list_clipping)(int items_count, float items_height, int* out_items_display_start, int* out_items_display_end)
{
    return ImGui::CalcListClipping(items_count, items_height, out_items_display_start, out_items_display_end);
}

HL_PRIM bool HL_NAME(begin_child_frame)(ImGuiID id, vdynamic* size, ImGuiWindowFlags* flags)
{
    return ImGui::BeginChildFrame(id, getImVec2(size), convertPtr(flags, 0));
}

HL_PRIM void HL_NAME(end_child_frame)()
{
    ImGui::EndChildFrame();
}

DEFINE_PRIM(_BOOL, is_rect_visible, _DYN);
DEFINE_PRIM(_BOOL, is_rect_visible2, _DYN _DYN);
DEFINE_PRIM(_F64, get_time, _NO_ARG);
DEFINE_PRIM(_I32, get_frame_count, _NO_ARG);
DEFINE_PRIM(_BYTES, get_style_color_name, _I32);
DEFINE_PRIM(_VOID, calc_list_clipping, _I32 _F32 _REF(_I32) _REF(_I32));
DEFINE_PRIM(_BOOL, begin_child_frame, _I32 _DYN _REF(_I32));
DEFINE_PRIM(_VOID, end_child_frame, _NO_ARG);
