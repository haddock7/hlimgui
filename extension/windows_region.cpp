#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM vdynamic* HL_NAME(get_content_region_max)()
{
	return getHLFromImVec2(ImGui::GetContentRegionMax());
}

HL_PRIM vdynamic* HL_NAME(get_content_region_avail)()
{
	return getHLFromImVec2(ImGui::GetContentRegionAvail());
}

HL_PRIM vdynamic* HL_NAME(get_window_content_region_min)()
{
	return getHLFromImVec2(ImGui::GetWindowContentRegionMin());
}

HL_PRIM vdynamic* HL_NAME(get_window_content_region_max)()
{
	return getHLFromImVec2(ImGui::GetWindowContentRegionMax());
}

HL_PRIM float HL_NAME(get_window_content_region_width)()
{
	return ImGui::GetWindowContentRegionWidth();
}

DEFINE_PRIM(_DYN, get_content_region_max, _NO_ARG);
DEFINE_PRIM(_DYN, get_content_region_avail, _NO_ARG);
DEFINE_PRIM(_DYN, get_window_content_region_min, _NO_ARG);
DEFINE_PRIM(_DYN, get_window_content_region_max, _NO_ARG);
DEFINE_PRIM(_F32, get_window_content_region_width, _NO_ARG);
