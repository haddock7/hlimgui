#pragma once

#include <hl.h>
#include "imgui/imgui.h"

ImGuiStyle getImGuiStyleFromHL(vdynamic* style);
vdynamic* getHLFromImGuiStyle(const ImGuiStyle& imgui_style);

ImVec2 getImVec2(vdynamic* vec2, const ImVec2& default_value = ImVec2(0, 0));
ImVec4 getImVec4(vdynamic* vec4, const ImVec4& default_value = ImVec4(0, 0, 0, 0));
vdynamic* getHLFromImVec2(ImVec2 value);