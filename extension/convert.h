#pragma once

#include <string>
#include <hl.h>
#include "imgui/imgui.h"

void convertColor(ImU32 color, float& r, float& g, float& b, float& a);
std::string unicodeToUTF8(vstring* hl_string);

