#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM void HL_NAME(text)(vstring* text)
{
    ImGui::TextUnformatted(convertString(text));
}

HL_PRIM void HL_NAME(text_colored)(vdynamic* col, vstring* text)
{
    ImGui::TextColored(getImVec4(col), "%s", convertString(text));
}

HL_PRIM void HL_NAME(text_disabled)(vstring* text)
{
    ImGui::TextDisabled("%s", convertString(text));
}

HL_PRIM void HL_NAME(text_wrapped)(vstring* text)
{
    ImGui::TextWrapped("%s", convertString(text));
}

HL_PRIM void HL_NAME(label_text)(vstring* label, vstring* text)
{
    ImGui::LabelText(convertString(label), "%s", convertString(text));
}

HL_PRIM void HL_NAME(bullet_text)(vstring* text)
{
    ImGui::BulletText("%s", convertString(text));
}

DEFINE_PRIM(_VOID, text, _STRING);
DEFINE_PRIM(_VOID, text_colored, _DYN _STRING);
DEFINE_PRIM(_VOID, text_disabled, _STRING);
DEFINE_PRIM(_VOID, text_wrapped, _STRING);
DEFINE_PRIM(_VOID, label_text, _STRING _STRING);
DEFINE_PRIM(_VOID, bullet_text, _STRING);
