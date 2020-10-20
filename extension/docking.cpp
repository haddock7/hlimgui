#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM void HL_NAME(dock_space)(int id, vdynamic* size, ImGuiDockNodeFlags* flags)
{
	ImGui::DockSpace(ImGuiID(id), getImVec2(size), convertPtr(flags, 0));
}

DEFINE_PRIM(_VOID, dock_space, _I32 _DYN _REF(_I32));