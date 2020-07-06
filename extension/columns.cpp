#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM void HL_NAME(columns)(int* count, vstring* id, bool* border)
{
    ImGui::Columns(convertPtr(count, 1), convertString(id), convertPtr(border, true));
}

HL_PRIM void HL_NAME(next_column)()
{
    ImGui::NextColumn();
}

HL_PRIM int HL_NAME(get_column_index)()
{
    return ImGui::GetColumnIndex();
}

HL_PRIM float HL_NAME(get_column_width)(int* column_index)
{
    return ImGui::GetColumnWidth(convertPtr(column_index, -1));
}

HL_PRIM void HL_NAME(set_column_width)(int column_index, float width)
{
    ImGui::SetColumnWidth(column_index, width);
}

HL_PRIM float HL_NAME(get_column_offset)(int* column_index)
{
    return ImGui::GetColumnOffset(convertPtr(column_index, -1));
}

HL_PRIM void HL_NAME(set_column_offset)(int column_index, float offset_x)
{
    ImGui::SetColumnOffset(column_index, offset_x);
}

HL_PRIM int HL_NAME(get_columns_count)()
{
    return ImGui::GetColumnsCount();
}

DEFINE_PRIM(_VOID, columns, _REF(_I32) _STRING _REF(_BOOL));
DEFINE_PRIM(_VOID, next_column, _NO_ARG);
DEFINE_PRIM(_I32, get_column_index, _NO_ARG);
DEFINE_PRIM(_F32, get_column_width, _REF(_I32));
DEFINE_PRIM(_VOID, set_column_width, _I32 _F32);
DEFINE_PRIM(_F32, get_column_offset, _REF(_I32));
DEFINE_PRIM(_VOID, set_column_offset, _I32 _F32);
DEFINE_PRIM(_I32, get_columns_count, _NO_ARG);
