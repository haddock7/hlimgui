#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM void HL_NAME(log_to_tty)(int* auto_open_depth)
{
    ImGui::LogToTTY(convertPtr(auto_open_depth, -1));
}

HL_PRIM void HL_NAME(log_to_file)(int* auto_open_depth, vstring* filename)
{
    ImGui::LogToFile(convertPtr(auto_open_depth, -1), convertString(filename));
}

HL_PRIM void HL_NAME(log_to_clipboard)(int* auto_open_depth)
{
    ImGui::LogToClipboard(convertPtr(auto_open_depth, -1));
}

HL_PRIM void HL_NAME(log_finish)()
{
    ImGui::LogFinish();
}

HL_PRIM void HL_NAME(log_buttons)()
{
    ImGui::LogButtons();
}

HL_PRIM void HL_NAME(log_text)(vstring* text)
{
    ImGui::LogText("%s", convertString(text));
}

DEFINE_PRIM(_VOID, log_to_tty, _REF(_I32));
DEFINE_PRIM(_VOID, log_to_file, _REF(_I32) _STRING);
DEFINE_PRIM(_VOID, log_to_clipboard, _REF(_I32));
DEFINE_PRIM(_VOID, log_finish, _NO_ARG);
DEFINE_PRIM(_VOID, log_buttons, _NO_ARG);
DEFINE_PRIM(_VOID, log_text, _STRING);
