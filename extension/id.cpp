#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "convert.h"

HL_PRIM void HL_NAME(push_id)(vstring* str_id)
{
	ImGui::PushID(unicodeToUTF8(str_id).c_str());
}

HL_PRIM void HL_NAME(push_id2)(vstring* str_id_begin, vstring* str_id_end)
{
	ImGui::PushID(unicodeToUTF8(str_id_begin).c_str(), unicodeToUTF8(str_id_end).c_str());
}

HL_PRIM void HL_NAME(push_id3)(int int_id)
{
	ImGui::PushID(int_id);
}

HL_PRIM void HL_NAME(pop_id)()
{
	ImGui::PopID();
}

HL_PRIM ImGuiID HL_NAME(get_id)(vstring* str_id)
{
	return ImGui::GetID(unicodeToUTF8(str_id).c_str());
}

HL_PRIM ImGuiID HL_NAME(get_id2)(vstring* str_id_begin, vstring* str_id_end)
{
	return ImGui::GetID(unicodeToUTF8(str_id_begin).c_str(), unicodeToUTF8(str_id_end).c_str());
}

DEFINE_PRIM(_VOID, push_id, _STRING);
DEFINE_PRIM(_VOID, push_id2, _STRING _STRING);
DEFINE_PRIM(_VOID, push_id3, _I32);
DEFINE_PRIM(_VOID, pop_id, _NO_ARG);
DEFINE_PRIM(_I32, get_id, _STRING);
DEFINE_PRIM(_I32, get_id2, _STRING _STRING);
