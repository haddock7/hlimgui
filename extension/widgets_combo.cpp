#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include <vector>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM bool HL_NAME(begin_combo)(vstring* label, vstring* preview_value, ImGuiComboFlags* flags)
{
    return ImGui::BeginCombo(convertString(label), convertString(preview_value), convertPtr(flags, 0));
}

HL_PRIM void HL_NAME(end_combo)()
{
    ImGui::EndCombo();
}

HL_PRIM bool HL_NAME(combo)(vstring* label, int* current_item, varray* items, int* popup_max_height_in_items)
{
    std::vector<std::string> utf8_items;
	for (int i = 0; i < items->size; i++)
    {
        utf8_items.push_back(unicodeToUTF8(hl_aptr(items, vstring*)[i]));
    }

    std::vector<const char*> cstr_items;
   	for (int i = 0; i < items->size; i++)
    {
        cstr_items.push_back(utf8_items[i].c_str());
    }

    return ImGui::Combo(convertString(label), current_item, &cstr_items[0], items->size, convertPtr(popup_max_height_in_items, -1));
}

HL_PRIM bool HL_NAME(combo2)(vstring* label, int* current_item, vstring* items_separated_by_zeros, int* popup_max_height_in_items)
{
    return ImGui::Combo(convertString(label), current_item, convertString(items_separated_by_zeros), convertPtr(popup_max_height_in_items, -1));
}

DEFINE_PRIM(_BOOL, begin_combo, _STRING _STRING _REF(_I32));
DEFINE_PRIM(_VOID, end_combo, _NO_ARG);
DEFINE_PRIM(_BOOL, combo, _STRING _REF(_I32) _ARR _REF(_I32));
DEFINE_PRIM(_BOOL, combo2, _STRING _REF(_I32) _STRING _REF(_I32));
