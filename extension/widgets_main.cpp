#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "struct.h"
#include "convert.h"

HL_PRIM bool HL_NAME(button)(vstring* label, vdynamic* size)
{
	return ImGui::Button(unicodeToUTF8(label).c_str(), getImVec2(size));
}

HL_PRIM bool HL_NAME(small_button)(vstring* label)
{
	return ImGui::SmallButton(unicodeToUTF8(label).c_str());
}

HL_PRIM bool HL_NAME(invisible_button)(vstring* str_id, vdynamic* size)
{
	return ImGui::InvisibleButton(unicodeToUTF8(str_id).c_str(), getImVec2(size));
}

HL_PRIM bool HL_NAME(arrow_button)(vstring* str_id, ImGuiDir dir)
{
	return ImGui::ArrowButton(unicodeToUTF8(str_id).c_str(), dir);
}

HL_PRIM void HL_NAME(image)(ImTextureID user_texture_id, vdynamic* size, vdynamic* uv0, vdynamic* uv1, vdynamic* tint_col, vdynamic* border_col)
{
	return ImGui::Image(
		user_texture_id,
		getImVec2(size),
		getImVec2(uv0),
		getImVec2(uv1, ImVec2(1, 1)),
		getImVec4(tint_col, ImVec4(1, 1, 1, 1)),
		getImVec4(border_col));
}

HL_PRIM bool HL_NAME(image_button)(ImTextureID user_texture_id, vdynamic* size, vdynamic* uv0, vdynamic* uv1, int* frame_padding, vdynamic* bg_col, vdynamic* tint_col)
{
	return ImGui::ImageButton(
		user_texture_id, 
		getImVec2(size), 
		getImVec2(uv0), 
		getImVec2(uv1, ImVec2(1, 1)), 
		frame_padding != nullptr ? *frame_padding : -1, 
		getImVec4(bg_col), 
		getImVec4(tint_col, ImVec4(1, 1, 1, 1)));
}

HL_PRIM bool HL_NAME(checkbox)(vstring* label, bool* v)
{
	return ImGui::Checkbox(unicodeToUTF8(label).c_str(), v);
}

HL_PRIM bool HL_NAME(checkbox_flags)(vstring* label, unsigned int* flags, unsigned int flags_value)
{
	return ImGui::CheckboxFlags(unicodeToUTF8(label).c_str(), flags, flags_value);
}

HL_PRIM bool HL_NAME(radio_button)(vstring* label, bool active)
{
	return ImGui::RadioButton(unicodeToUTF8(label).c_str(), active);
}

HL_PRIM bool HL_NAME(radio_button2)(vstring* label, int* v, int v_button)
{
	return ImGui::RadioButton(unicodeToUTF8(label).c_str(), v, v_button);
}

HL_PRIM void HL_NAME(progress_bar)(float fraction, vdynamic* size_arg, vstring* overlay)
{
	ImGui::ProgressBar(fraction, getImVec2(size_arg, ImVec2(-1, 0)), overlay != nullptr ? unicodeToUTF8(overlay).c_str() : NULL);
}

HL_PRIM void HL_NAME(bullet)()
{
	ImGui::Bullet();
}

DEFINE_PRIM(_BOOL, button, _STRING _DYN);
DEFINE_PRIM(_BOOL, small_button, _STRING);
DEFINE_PRIM(_BOOL, invisible_button, _STRING _DYN);
DEFINE_PRIM(_BOOL, arrow_button, _STRING _I32);
DEFINE_PRIM(_VOID, image, _I32 _DYN _DYN _DYN _DYN _DYN);
DEFINE_PRIM(_BOOL, image_button, _I32 _DYN _DYN _DYN _REF(_I32) _DYN _DYN);
DEFINE_PRIM(_BOOL, checkbox, _STRING _REF(_BOOL));
DEFINE_PRIM(_BOOL, checkbox_flags, _STRING _REF(_I32) _I32);
DEFINE_PRIM(_BOOL, radio_button, _STRING _BOOL);
DEFINE_PRIM(_BOOL, radio_button2, _STRING _REF(_I32) _I32);
DEFINE_PRIM(_VOID, progress_bar, _F32 _DYN _STRING);
DEFINE_PRIM(_VOID, bullet, _NO_ARG);
