#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

static std::string ini_filename;

HL_PRIM bool HL_NAME(want_capture_mouse)()
{
    return ImGui::GetIO().WantCaptureMouse;
}

HL_PRIM bool HL_NAME(want_capture_keyboard)()
{
    return ImGui::GetIO().WantCaptureMouse;
}

HL_PRIM void HL_NAME(set_ini_filename)(vstring* filename)
{
    if (filename == nullptr) 
    {
        ImGui::GetIO().IniFilename = NULL;
    }
    else
    {
        ini_filename = convertString(filename);
    }
    ImGui::GetIO().IniFilename = ini_filename.c_str();
}

HL_PRIM void HL_NAME(set_config_flags)(ImGuiConfigFlags* flags)
{
    ImGui::GetIO().ConfigFlags = convertPtr(flags, 0);
}

DEFINE_PRIM(_BOOL, want_capture_mouse, _NO_ARG);
DEFINE_PRIM(_BOOL, want_capture_keyboard, _NO_ARG);
DEFINE_PRIM(_VOID, set_ini_filename, _STRING);
DEFINE_PRIM(_VOID, set_config_flags, _REF(_I32));
