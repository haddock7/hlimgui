#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM void HL_NAME(begin_tooltip)()
{
    ImGui::BeginTooltip();
}

HL_PRIM void HL_NAME(end_tooltip)()
{
    ImGui::EndTooltip();
}

HL_PRIM void HL_NAME(set_tooltip)(vstring* fmt)
{
    ImGui::SetTooltip("%s", convertStringNullAsEmpty(fmt));
}

DEFINE_PRIM(_VOID, begin_tooltip, _NO_ARG);
DEFINE_PRIM(_VOID, end_tooltip, _NO_ARG);
DEFINE_PRIM(_VOID, set_tooltip, _STRING);
