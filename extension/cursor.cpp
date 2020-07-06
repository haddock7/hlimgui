#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM void HL_NAME(separator)()
{
	ImGui::Separator();
}

HL_PRIM void HL_NAME(same_line)(float* offset_from_start_x, float* spacing)
{
	ImGui::SameLine(offset_from_start_x != nullptr ? *offset_from_start_x : 0.0f, spacing != nullptr ? *spacing : -1.0f);
}

HL_PRIM void HL_NAME(new_line)()
{
	ImGui::NewLine();
}

HL_PRIM void HL_NAME(spacing)()
{
	ImGui::Spacing();
}

HL_PRIM void HL_NAME(dummy)(vdynamic* size)
{
	ImGui::Dummy(getImVec2(size));
}

HL_PRIM void HL_NAME(indent)(float* indent_w)
{
	ImGui::Indent(indent_w != nullptr ? *indent_w : 0.0f);
}

HL_PRIM void HL_NAME(unindent)(float* indent_w)
{
	ImGui::Unindent(indent_w != nullptr ? *indent_w : 0.0f);
}

HL_PRIM void HL_NAME(begin_group)()
{
	ImGui::BeginGroup();
}

HL_PRIM void HL_NAME(end_group)()
{
	ImGui::EndGroup();
}

HL_PRIM vdynamic* HL_NAME(get_cursor_pos)()
{
	return getHLFromImVec2(ImGui::GetCursorPos());
}

HL_PRIM float HL_NAME(get_cursor_pos_x)()
{
	return ImGui::GetCursorPosX();
}

HL_PRIM float HL_NAME(get_cursor_pos_y)()
{
	return ImGui::GetCursorPosY();
}

HL_PRIM void HL_NAME(set_cursor_pos)(vdynamic* local_pos)
{
	ImGui::SetCursorPos(getImVec2(local_pos));
}

HL_PRIM void HL_NAME(set_cursor_pos_x)(float local_x)
{
	ImGui::SetCursorPosX(local_x);
}

HL_PRIM void HL_NAME(set_cursor_pos_y)(float local_y)
{
	ImGui::SetCursorPosY(local_y);
}

HL_PRIM vdynamic* HL_NAME(get_cursor_start_pos)()
{
	return getHLFromImVec2(ImGui::GetCursorStartPos());
}

HL_PRIM vdynamic* HL_NAME(get_cursor_screen_pos)()
{
	return getHLFromImVec2(ImGui::GetCursorScreenPos());
}

HL_PRIM void HL_NAME(set_cursor_screen_pos)(vdynamic* pos)
{
	ImGui::SetCursorScreenPos(getImVec2(pos));
}

HL_PRIM void HL_NAME(align_text_to_frame_padding)()
{
	ImGui::AlignTextToFramePadding();
}

HL_PRIM float HL_NAME(get_text_line_height)()
{
	return ImGui::GetTextLineHeight();
}

HL_PRIM float HL_NAME(get_text_line_height_with_spacing)()
{
	return ImGui::GetTextLineHeightWithSpacing();
}

HL_PRIM float HL_NAME(get_frame_height)()
{
	return ImGui::GetFrameHeight();
}

HL_PRIM float HL_NAME(get_frame_height_with_spacing)()
{
	return ImGui::GetFrameHeightWithSpacing();
}

DEFINE_PRIM(_VOID, separator, _NO_ARG);
DEFINE_PRIM(_VOID, same_line, _REF(_F32) _REF(_F32));
DEFINE_PRIM(_VOID, new_line, _NO_ARG);
DEFINE_PRIM(_VOID, spacing, _NO_ARG);
DEFINE_PRIM(_VOID, dummy, _DYN);
DEFINE_PRIM(_VOID, indent, _REF(_F32));
DEFINE_PRIM(_VOID, unindent, _REF(_F32));
DEFINE_PRIM(_VOID, begin_group, _NO_ARG);
DEFINE_PRIM(_VOID, end_group, _NO_ARG);
DEFINE_PRIM(_DYN, get_cursor_pos, _NO_ARG);
DEFINE_PRIM(_F32, get_cursor_pos_x, _NO_ARG);
DEFINE_PRIM(_F32, get_cursor_pos_y, _NO_ARG);
DEFINE_PRIM(_VOID, set_cursor_pos, _DYN);
DEFINE_PRIM(_VOID, set_cursor_pos_x, _F32);
DEFINE_PRIM(_VOID, set_cursor_pos_y, _F32);
DEFINE_PRIM(_DYN, get_cursor_start_pos, _NO_ARG);
DEFINE_PRIM(_DYN, get_cursor_screen_pos, _NO_ARG);
DEFINE_PRIM(_VOID, set_cursor_screen_pos, _DYN);
DEFINE_PRIM(_VOID, align_text_to_frame_padding, _NO_ARG);
DEFINE_PRIM(_F32, get_text_line_height, _NO_ARG);
DEFINE_PRIM(_F32, get_text_line_height_with_spacing, _NO_ARG);
DEFINE_PRIM(_F32, get_frame_height, _NO_ARG);
DEFINE_PRIM(_F32, get_frame_height_with_spacing, _NO_ARG);
