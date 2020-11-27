#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"

HL_PRIM float HL_NAME(get_scroll_x)()
{
	return ImGui::GetScrollX();
}

HL_PRIM float HL_NAME(get_scroll_y)()
{
	return ImGui::GetScrollY();
}

HL_PRIM float HL_NAME(get_scroll_max_x)()
{
	return ImGui::GetScrollMaxX();
}

HL_PRIM float HL_NAME(get_scroll_max_y)()
{
	return ImGui::GetScrollMaxY();
}

HL_PRIM void HL_NAME(set_scroll_x)(float scroll_x)
{
	ImGui::SetScrollX(scroll_x);
}

HL_PRIM void HL_NAME(set_scroll_y)(float scroll_y)
{
	ImGui::SetScrollY(scroll_y);
}

HL_PRIM void HL_NAME(set_scroll_here_x)(float* center_x_ratio)
{
	ImGui::SetScrollHereX(center_x_ratio != nullptr ? *center_x_ratio : 0.5f);
}

HL_PRIM void HL_NAME(set_scroll_here_y)(float* center_y_ratio)
{
	ImGui::SetScrollHereY(center_y_ratio != nullptr ? *center_y_ratio : 0.5f);
}

HL_PRIM void HL_NAME(set_scroll_from_pos_x)(float local_x, float* center_x_ratio)
{
	ImGui::SetScrollFromPosX(local_x, center_x_ratio != nullptr ? *center_x_ratio : 0.5f);
}

HL_PRIM void HL_NAME(set_scroll_from_pos_y)(float local_y, float* center_y_ratio)
{
	ImGui::SetScrollFromPosY(local_y, center_y_ratio != nullptr ? *center_y_ratio : 0.5f);
}

DEFINE_PRIM(_F32, get_scroll_x, _NO_ARG);
DEFINE_PRIM(_F32, get_scroll_y, _NO_ARG);
DEFINE_PRIM(_F32, get_scroll_max_x, _NO_ARG);
DEFINE_PRIM(_F32, get_scroll_max_y, _NO_ARG);
DEFINE_PRIM(_VOID, set_scroll_x, _F32);
DEFINE_PRIM(_VOID, set_scroll_y, _F32);
DEFINE_PRIM(_VOID, set_scroll_here_x, _REF(_F32));
DEFINE_PRIM(_VOID, set_scroll_here_y, _REF(_F32));
DEFINE_PRIM(_VOID, set_scroll_from_pos_x, _F32 _REF(_F32));
DEFINE_PRIM(_VOID, set_scroll_from_pos_y, _F32 _REF(_F32));
