#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM void HL_NAME(style_colors_dark)(vdynamic* hl_style)
{
	if (hl_style != nullptr) {
		ImGuiStyle style = getImGuiStyleFromHL(hl_style);
		ImGui::StyleColorsDark(&style);
	}
	else
	{
		ImGui::StyleColorsDark(NULL);
	}
}

HL_PRIM void HL_NAME(style_colors_classic)(vdynamic* hl_style)
{
	if (hl_style != nullptr) {
		ImGuiStyle style = getImGuiStyleFromHL(hl_style);
		ImGui::StyleColorsClassic(&style);
	}
	else
	{
		ImGui::StyleColorsClassic(NULL);
	}
}

HL_PRIM void HL_NAME(style_colors_light)(vdynamic* hl_style)
{
	if (hl_style != nullptr) {
		ImGuiStyle style = getImGuiStyleFromHL(hl_style);
		ImGui::StyleColorsLight(&style);
	}
	else
	{
		ImGui::StyleColorsLight(NULL);
	}
}

DEFINE_PRIM(_VOID, style_colors_dark, _DYN);
DEFINE_PRIM(_VOID, style_colors_classic, _DYN);
DEFINE_PRIM(_VOID, style_colors_light, _DYN);
