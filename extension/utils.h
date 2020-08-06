#pragma once

#include <string>
#include <hl.h>
#include "imgui/imgui.h"

#define convertString(st) st != nullptr ? unicodeToUTF8(st).c_str() : NULL
#define convertStringNullAsEmpty(st) st != nullptr ? unicodeToUTF8(st).c_str() : ""
#define convertPtr(ptr,default_value) ptr != nullptr ? *ptr : default_value

#ifdef __APPLE__
#define throw_error(err) hl_throw(hl_alloc_strbytes((const uchar*)(USTR(err))))
#else
#define throw_error(err) hl_error(err)
#endif

void convertColor(ImU32 color, float& r, float& g, float& b, float& a);
std::string unicodeToUTF8(vstring* hl_string);

ImGuiStyle getImGuiStyleFromHL(vdynamic* style);
vdynamic* getHLFromImGuiStyle(const ImGuiStyle& imgui_style);

ImVec2 getImVec2(vdynamic* vec2, const ImVec2& default_value = ImVec2(0, 0));
ImVec4 getImVec4(vdynamic* vec4, const ImVec4& default_value = ImVec4(0, 0, 0, 0));

vdynamic* getHLFromImVec2(ImVec2 value);
vdynamic* getHLFromImVec4(ImVec4 value);

vbyte* getVByteFromCStr(const char* str);

inline void assertArraySize(varray* arr, int size) {if (arr->size != size) throw_error("Invalid array size");}
inline void assertArraySizeRange(varray* arr, int size_min, int size_max) {if (arr->size < size_min && arr->size > size_max) throw_error("Invalid array size");}
