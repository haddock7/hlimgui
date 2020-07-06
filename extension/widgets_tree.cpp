#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM bool HL_NAME(tree_node)(vstring* label)
{
    return ImGui::TreeNode(convertString(label));
}

HL_PRIM bool HL_NAME(tree_node2)(vstring* str_id, vstring* label)
{
    return ImGui::TreeNode(convertString(str_id), "%s", convertString(label));
}

HL_PRIM bool HL_NAME(tree_node_ex)(vstring* label, ImGuiTreeNodeFlags* flags)
{
    return ImGui::TreeNodeEx(convertString(label), convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(tree_node_ex2)(vstring* str_id, ImGuiTreeNodeFlags flags, vstring* label)
{
    return ImGui::TreeNodeEx(convertString(str_id), flags, "%s", convertString(label));
}

HL_PRIM void HL_NAME(tree_push)(vstring* str_id)
{
    ImGui::TreePush(convertString(str_id));
}

HL_PRIM void HL_NAME(tree_pop)()
{
    ImGui::TreePop();
}

HL_PRIM float HL_NAME(get_tree_node_to_label_spacing)()
{
    return ImGui::GetTreeNodeToLabelSpacing();
}

HL_PRIM bool HL_NAME(collapsing_header)(vstring* label, ImGuiTreeNodeFlags* flags)
{
    return ImGui::CollapsingHeader(convertString(label), convertPtr(flags, 0));
}

HL_PRIM bool HL_NAME(collapsing_header2)(vstring* label, bool* p_open, ImGuiTreeNodeFlags* flags)
{
    return ImGui::CollapsingHeader(convertString(label), p_open, convertPtr(flags, 0));
}

HL_PRIM void HL_NAME(set_next_item_open)(bool is_open, ImGuiCond* cond)
{
    ImGui::SetNextItemOpen(is_open, convertPtr(cond, 0));
}

DEFINE_PRIM(_BOOL, tree_node, _STRING);
DEFINE_PRIM(_BOOL, tree_node2, _STRING _STRING);
DEFINE_PRIM(_BOOL, tree_node_ex, _STRING _REF(_I32));
DEFINE_PRIM(_BOOL, tree_node_ex2, _STRING _I32 _STRING);
DEFINE_PRIM(_VOID, tree_push, _STRING);
DEFINE_PRIM(_VOID, tree_pop, _NO_ARG);
DEFINE_PRIM(_F32, get_tree_node_to_label_spacing, _NO_ARG);
DEFINE_PRIM(_BOOL, collapsing_header, _STRING _REF(_I32));
DEFINE_PRIM(_BOOL, collapsing_header2, _STRING _REF(_BOOL) _REF(_I32));
DEFINE_PRIM(_VOID, set_next_item_open, _BOOL _REF(_I32));
