#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"

HL_PRIM vbyte* HL_NAME(create_context)()
{
	vbyte* ptr = hl_alloc_bytes(sizeof(ImGuiContext*));
	*(ImGuiContext**)ptr = ImGui::CreateContext(NULL);

	return ptr;
}

HL_PRIM void HL_NAME(destroy_context)(vbyte* ptr)
{
	ImGuiContext* ctx = ptr == nullptr ? NULL : *(ImGuiContext**)ptr;
	ImGui::DestroyContext(ctx);
}

HL_PRIM vbyte* HL_NAME(get_current_context)()
{
	vbyte* ptr = hl_alloc_bytes(sizeof(ImGuiContext*));
	*(ImGuiContext**)ptr = ImGui::GetCurrentContext();

	return ptr;
}

HL_PRIM void HL_NAME(set_current_context)(vbyte* ptr)
{
	ImGui::SetCurrentContext(*(ImGuiContext**)ptr);
}

DEFINE_PRIM(_BYTES, create_context, _NO_ARG);
DEFINE_PRIM(_VOID, destroy_context, _BYTES);
DEFINE_PRIM(_BYTES, get_current_context, _NO_ARG);
DEFINE_PRIM(_VOID, set_current_context, _BYTES);
