#pragma once

#include <string>
#include <hl.h>
#include "imgui/imgui.h"

#define convertString(st) st != nullptr ? unicodeToUTF8(st).c_str() : NULL
#define convertPtr(ptr,default_value) ptr != nullptr ? *ptr : default_value

void convertColor(ImU32 color, float& r, float& g, float& b, float& a);
std::string unicodeToUTF8(vstring* hl_string);

