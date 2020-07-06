#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM void HL_NAME(push_style_color)(ImGuiCol idx, ImU32 col)
{
	ImGui::PushStyleColor(idx, col);
}
DEFINE_PRIM(_VOID, push_style_color, _I32 _I32);

HL_PRIM void HL_NAME(push_style_color2)(ImGuiCol idx, vdynamic* col)
{
	ImGui::PushStyleColor(idx, getImVec4(col));
}
DEFINE_PRIM(_VOID, push_style_color2, _I32 _DYN);

HL_PRIM void HL_NAME(pop_style_color)(int* count)
{
	ImGui::PopStyleColor(count != nullptr ? *count : 1);
}
DEFINE_PRIM(_VOID, pop_style_color, _REF(_I32));

HL_PRIM void HL_NAME(push_style_var)(ImGuiStyleVar idx, float val)
{
	ImGui::PushStyleVar(idx, val);
}
DEFINE_PRIM(_VOID, push_style_var, _I32 _F32);

HL_PRIM void HL_NAME(push_style_var2)(ImGuiStyleVar idx, vdynamic* val)
{
	ImGui::PushStyleVar(idx, getImVec2(val));
}
DEFINE_PRIM(_VOID, push_style_var2, _I32 _DYN);

HL_PRIM void HL_NAME(pop_style_var)(int* count)
{
	ImGui::PopStyleVar(count != nullptr ? *count : 1);
}
DEFINE_PRIM(_VOID, pop_style_var, _REF(_I32));

IMGUI_API vdynamic* HL_NAME(get_style_color_vec4)(ImGuiCol idx)
{
	return getHLFromImVec4(ImGui::GetStyleColorVec4(idx));
}
DEFINE_PRIM(_DYN, get_style_color_vec4, _I32);

HL_PRIM float HL_NAME(get_font_size)()
{
	return ImGui::GetFontSize();
}
DEFINE_PRIM(_F32, get_font_size, _NO_ARG);

HL_PRIM vdynamic* HL_NAME(get_font_tex_uv_white_pixel)()
{
	return getHLFromImVec2(ImGui::GetFontTexUvWhitePixel());
}
DEFINE_PRIM(_DYN, get_font_tex_uv_white_pixel, _NO_ARG);

HL_PRIM ImU32 HL_NAME(get_color_u32)(ImGuiCol idx, float* alpha_mul)
{
	return ImGui::GetColorU32(idx, convertPtr(alpha_mul, 1.0f));
}
DEFINE_PRIM(_I32, get_color_u32, _I32 _REF(_F32));

HL_PRIM ImU32 HL_NAME(get_color_u322)(vdynamic* col)
{
	return ImGui::GetColorU32(getImVec4(col));
}
DEFINE_PRIM(_I32, get_color_u322, _DYN);

HL_PRIM ImU32 HL_NAME(get_color_u323)(ImU32 col)
{
	return ImGui::GetColorU32(col);
}
DEFINE_PRIM(_I32, get_color_u323, _I32);

HL_PRIM void HL_NAME(push_item_width)(float item_width)
{
	ImGui::PushItemWidth(item_width);
}
DEFINE_PRIM(_VOID, push_item_width, _F32);

HL_PRIM void HL_NAME(pop_item_width)()
{
	ImGui::PopItemWidth();
}
DEFINE_PRIM(_VOID, pop_item_width, _NO_ARG);

HL_PRIM void HL_NAME(set_next_item_width)(float item_width)
{
	ImGui::SetNextItemWidth(item_width);
}
DEFINE_PRIM(_VOID, set_next_item_width, _F32);

HL_PRIM float HL_NAME(calc_item_width)()
{
	return ImGui::CalcItemWidth();
}
DEFINE_PRIM(_F32, calc_item_width, _NO_ARG);

HL_PRIM void HL_NAME(push_text_wrap_pos)(float* wrap_local_pos_x)
{
	ImGui::PushTextWrapPos(convertPtr(wrap_local_pos_x, 0.0f));
}
DEFINE_PRIM(_VOID, push_text_wrap_pos, _REF(_F32));

HL_PRIM void HL_NAME(pop_text_wrap_pos)()
{
	ImGui::PopTextWrapPos();
}
DEFINE_PRIM(_VOID, pop_text_wrap_pos, _NO_ARG);

HL_PRIM void HL_NAME(push_allow_keyboard_focus)(bool allow_keyboard_focus)
{
	ImGui::PushAllowKeyboardFocus(allow_keyboard_focus);
}
DEFINE_PRIM(_VOID, push_allow_keyboard_focus, _BOOL);

HL_PRIM void HL_NAME(pop_allow_keyboard_focus)()
{
	ImGui::PopAllowKeyboardFocus();
}
DEFINE_PRIM(_VOID, pop_allow_keyboard_focus, _NO_ARG);

HL_PRIM void HL_NAME(push_button_repeat)(bool repeat)
{
	ImGui::PushButtonRepeat(repeat);
}
DEFINE_PRIM(_VOID, push_button_repeat, _BOOL);

HL_PRIM void HL_NAME(pop_button_repeat)()
{
	ImGui::PopButtonRepeat();
}
DEFINE_PRIM(_VOID, pop_button_repeat, _NO_ARG);

