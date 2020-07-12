#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM void HL_NAME(push_clip_rect)(vdynamic* clip_rect_min, vdynamic* clip_rect_max, bool intersect_with_current_clip_rect)
{
    ImGui::PushClipRect(getImVec2(clip_rect_min), getImVec2(clip_rect_max), intersect_with_current_clip_rect);
}

HL_PRIM void HL_NAME(pop_clip_rect)()
{
    ImGui::PopClipRect();
}

DEFINE_PRIM(_VOID, push_clip_rect, _DYN _DYN _BOOL);
DEFINE_PRIM(_VOID, pop_clip_rect, _NO_ARG);
