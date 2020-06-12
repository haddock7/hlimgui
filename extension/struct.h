#pragma once

#include <hl.h>
#include "imgui/imgui.h"

ImGuiStyle getImGuiStyleFromHL(vdynamic* style);
vdynamic* getHLFromImGuiStyle(const ImGuiStyle& imgui_style);

ImVec2 getImVec2(vdynamic* vec2);
vdynamic* getHLFromImVec2(ImVec2 value);