#include "utils.h"
#include <vector>

void convertColor(ImU32 color, float& r, float& g, float& b, float& a)
{
	r = (color & 0xFF) / 255.0f;
	g = ((color >> 8) & 0xFF) / 255.0f;
	b = ((color >> 16) & 0xFF) / 255.0f;
	a = (color >> 24) / 255.0f;
}

std::string unicodeToUTF8(vstring* hl_string)
{
	std::string result;

	for (int i = 0; i < hl_string->length; i++)
	{
		auto code = ((unsigned short*)hl_string->bytes)[i];
		if (code <= 0x7F)
		{
			result += char(code);
		}
		else if (code <= 0x7FF) 
		{
			result += char(0xC0 | (code >> 6));            /* 110xxxxx */
			result += char(0x80 | (code & 0x3F));          /* 10xxxxxx */
		}
		else 
		{
			result += char(0xE0 | (code >> 12));           /* 1110xxxx */
			result += char(0x80 | ((code >> 6) & 0x3F));   /* 10xxxxxx */
			result += char(0x80 | (code & 0x3F));          /* 10xxxxxx */
		}
	}

	return result;
}

void getStructFloat(vdynamic* dyn, const char* name, float& value)
{
	value = hl_dyn_getf(dyn, hl_hash_utf8(name));
}

void setStructFloat(vdynamic* dyn, const char* name, float value)
{
	hl_dyn_setf(dyn, hl_hash_utf8(name), value);
}

void getStructInt(vdynamic* dyn, const char* name, int& value)
{
	value = hl_dyn_geti(dyn, hl_hash_utf8(name), &hlt_i32);
}

void setStructInt(vdynamic* dyn, const char* name, int value)
{
	hl_dyn_seti(dyn, hl_hash_utf8(name), &hlt_i32, value);
}

void getStructBool(vdynamic* dyn, const char* name, bool& value)
{
	value = (bool)hl_dyn_geti(dyn, hl_hash_utf8(name), &hlt_bool);
}

void setStructBool(vdynamic* dyn, const char* name, bool value)
{
	hl_dyn_seti(dyn, hl_hash_utf8(name), &hlt_bool, value);
}

void getStructImVec2(vdynamic* dyn, const char* name, ImVec2& value)
{
	vdynamic* vec2 = (vdynamic*)hl_dyn_getp(dyn, hl_hash_utf8(name), &hlt_dyn);
	getStructFloat(vec2, "x", value.x);
	getStructFloat(vec2, "y", value.y);
}

void setStructImVec2(vdynamic* dyn, const char* name, const ImVec2& value)
{
	vdynamic* vec2 = (vdynamic*)hl_alloc_dynobj();
	setStructFloat(vec2, "x", value.x);
	setStructFloat(vec2, "y", value.y);
	hl_dyn_setp(dyn, hl_hash_utf8(name), &hlt_dynobj, vec2);
}

void getStructArrayImVec4(vdynamic* dyn, const char* name, ImVec4* values, int size)
{
	varray* array = (varray*)hl_dyn_getp(dyn, hl_hash_utf8(name), &hlt_array);
	if (array->size < size)
	{
		size = array->size;
	}
	for (int i = 0; i < size; i++)
	{
		vdynamic* vec4 = hl_aptr(array, vdynamic*)[i];
		getStructFloat(vec4, "x", values[i].x);
		getStructFloat(vec4, "y", values[i].y);
		getStructFloat(vec4, "z", values[i].z);
		getStructFloat(vec4, "w", values[i].w);
	}
}

void setStructArrayImVec4(vdynamic* dyn, const char* name, const ImVec4* values, int size)
{
	varray* array = hl_alloc_array(&hlt_dynobj, size);
	for (int i = 0; i < size; i++)
	{
		vdynamic* vec4 = (vdynamic*)hl_alloc_dynobj();
		setStructFloat(vec4, "x", values[i].x);
		setStructFloat(vec4, "y", values[i].y);
		setStructFloat(vec4, "z", values[i].z);
		setStructFloat(vec4, "w", values[i].w);
		hl_aptr(array, vdynamic*)[i] = vec4;
	}
	hl_dyn_setp(dyn, hl_hash_utf8(name), &hlt_array, array);
}

ImGuiStyle getImGuiStyleFromHL(vdynamic* style)
{
	ImGuiStyle imgui_style;

	getStructFloat(style, "Alpha", imgui_style.Alpha);
	getStructImVec2(style, "WindowPadding", imgui_style.WindowPadding);
	getStructFloat(style, "WindowRounding", imgui_style.WindowRounding);
	getStructFloat(style, "WindowBorderSize", imgui_style.WindowBorderSize);
	getStructImVec2(style, "WindowMinSize", imgui_style.WindowMinSize);
	getStructImVec2(style, "WindowTitleAlign", imgui_style.WindowTitleAlign);
	getStructInt(style, "WindowMenuButtonPosition", imgui_style.WindowMenuButtonPosition);
	getStructFloat(style, "ChildRounding", imgui_style.ChildRounding);
	getStructFloat(style, "ChildBorderSize", imgui_style.ChildBorderSize);
	getStructFloat(style, "PopupRounding", imgui_style.PopupRounding);
	getStructFloat(style, "PopupBorderSize", imgui_style.PopupBorderSize);
	getStructImVec2(style, "FramePadding", imgui_style.FramePadding);
	getStructFloat(style, "FrameRounding", imgui_style.FrameRounding);
	getStructFloat(style, "FrameBorderSize", imgui_style.FrameBorderSize);
	getStructImVec2(style, "ItemSpacing", imgui_style.ItemSpacing);
	getStructImVec2(style, "ItemInnerSpacing", imgui_style.ItemInnerSpacing);
	getStructImVec2(style, "TouchExtraPadding", imgui_style.TouchExtraPadding);
	getStructFloat(style, "IndentSpacing", imgui_style.IndentSpacing);
	getStructFloat(style, "ColumnsMinSpacing", imgui_style.ColumnsMinSpacing);
	getStructFloat(style, "ScrollbarSize", imgui_style.ScrollbarSize);
	getStructFloat(style, "ScrollbarRounding", imgui_style.ScrollbarRounding);
	getStructFloat(style, "GrabMinSize", imgui_style.GrabMinSize);
	getStructFloat(style, "GrabRounding", imgui_style.GrabRounding);
	getStructFloat(style, "TabRounding", imgui_style.TabRounding);
	getStructFloat(style, "TabBorderSize", imgui_style.TabBorderSize);
	getStructFloat(style, "TabMinWidthForUnselectedCloseButton", imgui_style.TabMinWidthForUnselectedCloseButton);
	getStructInt(style, "ColorButtonPosition", imgui_style.ColorButtonPosition);
	getStructImVec2(style, "ButtonTextAlign", imgui_style.ButtonTextAlign);
	getStructImVec2(style, "SelectableTextAlign", imgui_style.SelectableTextAlign);
	getStructImVec2(style, "DisplayWindowPadding", imgui_style.DisplayWindowPadding);
	getStructImVec2(style, "DisplaySafeAreaPadding", imgui_style.DisplaySafeAreaPadding);
	getStructFloat(style, "MouseCursorScale", imgui_style.MouseCursorScale);
	getStructBool(style, "AntiAliasedLines", imgui_style.AntiAliasedLines);
	getStructBool(style, "AntiAliasedFill", imgui_style.AntiAliasedFill);
	getStructFloat(style, "CurveTessellationTol", imgui_style.CurveTessellationTol);
	getStructFloat(style, "CircleSegmentMaxError", imgui_style.CircleSegmentMaxError);
	getStructArrayImVec4(style, "Colors", imgui_style.Colors, ImGuiCol_COUNT);

	return imgui_style;
}

vdynamic* getHLFromImGuiStyle(const ImGuiStyle& imgui_style)
{
	vdynamic* style = (vdynamic*)hl_alloc_dynobj();

	setStructFloat(style, "Alpha", imgui_style.Alpha);
	setStructImVec2(style, "WindowPadding", imgui_style.WindowPadding);
	setStructFloat(style, "WindowRounding", imgui_style.WindowRounding);
	setStructFloat(style, "WindowBorderSize", imgui_style.WindowBorderSize);
	setStructImVec2(style, "WindowMinSize", imgui_style.WindowMinSize);
	setStructImVec2(style, "WindowTitleAlign", imgui_style.WindowTitleAlign);
	setStructInt(style, "WindowMenuButtonPosition", imgui_style.WindowMenuButtonPosition);
	setStructFloat(style, "ChildRounding", imgui_style.ChildRounding);
	setStructFloat(style, "ChildBorderSize", imgui_style.ChildBorderSize);
	setStructFloat(style, "PopupRounding", imgui_style.PopupRounding);
	setStructFloat(style, "PopupBorderSize", imgui_style.PopupBorderSize);
	setStructImVec2(style, "FramePadding", imgui_style.FramePadding);
	setStructFloat(style, "FrameRounding", imgui_style.FrameRounding);
	setStructFloat(style, "FrameBorderSize", imgui_style.FrameBorderSize);
	setStructImVec2(style, "ItemSpacing", imgui_style.ItemSpacing);
	setStructImVec2(style, "ItemInnerSpacing", imgui_style.ItemInnerSpacing);
	setStructImVec2(style, "TouchExtraPadding", imgui_style.TouchExtraPadding);
	setStructFloat(style, "IndentSpacing", imgui_style.IndentSpacing);
	setStructFloat(style, "ColumnsMinSpacing", imgui_style.ColumnsMinSpacing);
	setStructFloat(style, "ScrollbarSize", imgui_style.ScrollbarSize);
	setStructFloat(style, "ScrollbarRounding", imgui_style.ScrollbarRounding);
	setStructFloat(style, "GrabMinSize", imgui_style.GrabMinSize);
	setStructFloat(style, "GrabRounding", imgui_style.GrabRounding);
	setStructFloat(style, "TabRounding", imgui_style.TabRounding);
	setStructFloat(style, "TabBorderSize", imgui_style.TabBorderSize);
	setStructFloat(style, "TabMinWidthForUnselectedCloseButton", imgui_style.TabMinWidthForUnselectedCloseButton);
	setStructInt(style, "ColorButtonPosition", imgui_style.ColorButtonPosition);
	setStructImVec2(style, "ButtonTextAlign", imgui_style.ButtonTextAlign);
	setStructImVec2(style, "SelectableTextAlign", imgui_style.SelectableTextAlign);
	setStructImVec2(style, "DisplayWindowPadding", imgui_style.DisplayWindowPadding);
	setStructImVec2(style, "DisplaySafeAreaPadding", imgui_style.DisplaySafeAreaPadding);
	setStructFloat(style, "MouseCursorScale", imgui_style.MouseCursorScale);
	setStructBool(style, "AntiAliasedLines", imgui_style.AntiAliasedLines);
	setStructBool(style, "AntiAliasedFill", imgui_style.AntiAliasedFill);
	setStructFloat(style, "CurveTessellationTol", imgui_style.CurveTessellationTol);
	setStructFloat(style, "CircleSegmentMaxError", imgui_style.CircleSegmentMaxError);
	setStructArrayImVec4(style, "Colors", imgui_style.Colors, ImGuiCol_COUNT);

	return style;
}

ImVec2 getImVec2(vdynamic* vec2, const ImVec2& default_value)
{
	ImVec2 result = default_value;
	if (vec2 != nullptr) {
		getStructFloat(vec2, "x", result.x);
		getStructFloat(vec2, "y", result.y);
	}
	return result;
}

ImVec4 getImVec4(vdynamic* vec4, const ImVec4& default_value)
{
	ImVec4 result = default_value;
	if (vec4 != nullptr) {
		getStructFloat(vec4, "x", result.x);
		getStructFloat(vec4, "y", result.y);
		getStructFloat(vec4, "z", result.z);
		getStructFloat(vec4, "w", result.w);
	}
	return result;
}

vdynamic* getHLFromImVec2(ImVec2 value)
{
	vdynamic* vec2 = (vdynamic*)hl_alloc_dynobj();
	setStructFloat(vec2, "x", value.x);
	setStructFloat(vec2, "y", value.y);
	return vec2;
}

vdynamic* getHLFromImVec4(ImVec4 value)
{
	vdynamic* vec4 = (vdynamic*)hl_alloc_dynobj();
	setStructFloat(vec4, "x", value.x);
	setStructFloat(vec4, "y", value.y);
	setStructFloat(vec4, "z", value.z);
	setStructFloat(vec4, "w", value.w);
	return vec4;
}
