#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM bool HL_NAME(is_window_appearing)()
{
	return ImGui::IsWindowAppearing();
}

HL_PRIM bool HL_NAME(is_window_collapsed)()
{
	return ImGui::IsWindowCollapsed();
}

HL_PRIM bool HL_NAME(is_window_focused)(ImGuiFocusedFlags* flags)
{
	return ImGui::IsWindowFocused(convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(is_window_hovered)(ImGuiFocusedFlags* flags)
{
	return ImGui::IsWindowHovered(convertPtr(flags, 0));
}

HL_PRIM vdynamic* HL_NAME(get_window_pos)()
{
	return getHLFromImVec2(ImGui::GetWindowPos());
}

HL_PRIM vdynamic* HL_NAME(get_window_size)()
{
	return getHLFromImVec2(ImGui::GetWindowSize());
}

HL_PRIM float HL_NAME(get_window_width)()
{
	return ImGui::GetWindowWidth();
}

HL_PRIM float HL_NAME(get_window_height)()
{
	return ImGui::GetWindowHeight();
}

HL_PRIM void HL_NAME(set_next_window_pos)(vdynamic* pos, ImGuiCond* cond, vdynamic* pivot)
{
	ImGui::SetNextWindowPos(getImVec2(pos), convertPtr(cond, 0), getImVec2(pivot));
}

HL_PRIM void HL_NAME(set_next_window_size)(vdynamic* size, ImGuiCond* cond)
{
	ImGui::SetNextWindowSize(getImVec2(size), convertPtr(cond, 0));
}

HL_PRIM void HL_NAME(set_next_window_size_constraints)(vdynamic* size_min, vdynamic* size_max)
{
	ImGui::SetNextWindowSizeConstraints(getImVec2(size_min), getImVec2(size_max));
}

HL_PRIM void HL_NAME(set_next_window_content_size)(vdynamic* size)
{
	ImGui::SetNextWindowContentSize(getImVec2(size));
}

HL_PRIM void HL_NAME(set_next_window_collapsed)(bool collapsed, ImGuiCond* cond)
{
	ImGui::SetNextWindowCollapsed(collapsed, convertPtr(cond, 0));
}

HL_PRIM void HL_NAME(set_next_window_focus)()
{
	ImGui::SetNextWindowFocus();
}

HL_PRIM void HL_NAME(set_next_window_bg_alpha)(float alpha)
{
	ImGui::SetNextWindowBgAlpha(alpha);
}

HL_PRIM void HL_NAME(set_window_pos)(vdynamic* pos, ImGuiCond* cond)
{
	ImGui::SetWindowPos(getImVec2(pos), convertPtr(cond, 0));
}

HL_PRIM void HL_NAME(set_window_size)(vdynamic* size, ImGuiCond* cond)
{
	ImGui::SetWindowSize(getImVec2(size), convertPtr(cond, 0));
}

HL_PRIM void HL_NAME(set_window_collapsed)(bool collapsed, ImGuiCond* cond)
{
	ImGui::SetWindowCollapsed(collapsed, convertPtr(cond, 0));
}

HL_PRIM void HL_NAME(set_window_focus)()
{
	ImGui::SetWindowFocus();
}

HL_PRIM void HL_NAME(set_window_font_scale)(float scale)
{
	ImGui::SetWindowFontScale(scale);
}

HL_PRIM void HL_NAME(set_window_pos2)(vstring* name, vdynamic* pos, ImGuiCond* cond)
{
	ImGui::SetWindowPos(unicodeToUTF8(name).c_str(), getImVec2(pos), convertPtr(cond, 0));
}

HL_PRIM void HL_NAME(set_window_size2)(vstring* name, vdynamic* size, ImGuiCond* cond)
{
	ImGui::SetWindowSize(unicodeToUTF8(name).c_str(), getImVec2(size), convertPtr(cond, 0));
}

HL_PRIM void HL_NAME(set_window_collapsed2)(vstring* name, bool collapsed, ImGuiCond* cond)
{
	ImGui::SetWindowCollapsed(unicodeToUTF8(name).c_str(), collapsed, convertPtr(cond, 0));
}

HL_PRIM void HL_NAME(set_window_focus2)(vstring* name)
{
	ImGui::SetWindowFocus(unicodeToUTF8(name).c_str());
}

DEFINE_PRIM(_BOOL, is_window_appearing, _NO_ARG);
DEFINE_PRIM(_BOOL, is_window_collapsed, _NO_ARG);
DEFINE_PRIM(_BOOL, is_window_focused, _REF(_I32));
DEFINE_PRIM(_BOOL, is_window_hovered, _REF(_I32));
DEFINE_PRIM(_DYN, get_window_pos, _NO_ARG);
DEFINE_PRIM(_DYN, get_window_size, _NO_ARG);
DEFINE_PRIM(_F32, get_window_width, _NO_ARG);
DEFINE_PRIM(_F32, get_window_height, _NO_ARG);
DEFINE_PRIM(_VOID, set_next_window_pos, _DYN _REF(_I32) _DYN);
DEFINE_PRIM(_VOID, set_next_window_size, _DYN _REF(_I32));
DEFINE_PRIM(_VOID, set_next_window_size_constraints, _DYN _DYN);
DEFINE_PRIM(_VOID, set_next_window_content_size, _DYN);
DEFINE_PRIM(_VOID, set_next_window_collapsed, _BOOL _REF(_I32));
DEFINE_PRIM(_VOID, set_next_window_focus, _NO_ARG);
DEFINE_PRIM(_VOID, set_next_window_bg_alpha, _F32);
DEFINE_PRIM(_VOID, set_window_pos, _DYN _REF(_I32));
DEFINE_PRIM(_VOID, set_window_size, _DYN _REF(_I32));
DEFINE_PRIM(_VOID, set_window_collapsed, _BOOL _REF(_I32));
DEFINE_PRIM(_VOID, set_window_focus, _NO_ARG);
DEFINE_PRIM(_VOID, set_window_font_scale, _F32);
DEFINE_PRIM(_VOID, set_window_pos2, _STRING _DYN _REF(_I32));
DEFINE_PRIM(_VOID, set_window_size2, _STRING _DYN _REF(_I32));
DEFINE_PRIM(_VOID, set_window_collapsed2, _STRING _BOOL _REF(_I32));
DEFINE_PRIM(_VOID, set_window_focus2, _STRING);

