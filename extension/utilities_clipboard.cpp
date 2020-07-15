#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include <vector>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM vbyte* HL_NAME(get_clipboard_text)()
{
    return getVByteFromCStr(ImGui::GetClipboardText());
}

HL_PRIM void HL_NAME(set_clipboard_text)(vstring* text)
{
    return ImGui::SetClipboardText(convertString(text));
}

DEFINE_PRIM(_BYTES, get_clipboard_text, _NO_ARG);
DEFINE_PRIM(_VOID, set_clipboard_text, _STRING);
