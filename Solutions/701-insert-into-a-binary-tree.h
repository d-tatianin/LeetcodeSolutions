#pragma once

// 701. You are given the root node of a binary search tree (BST) and a value to insert into the tree.
//      Return the root node of the BST after the insertion.
//      It is guaranteed that the new value does not exist in the original BST.

// Solution: (complexity O(Log N))
// Compare value against current node, if node's value is less,
// we go right, otherwise go left. If there's nowhere to go - become this node.

SOLUTION_FOR_PROBLEM(701, "Insert into a Binary Search Tree") {

TreeNode* insertIntoBST(TreeNode * root, int val) {
    auto* new_node = new TreeNode(val);
    auto ret_root = root;

    if (!root)
        return new_node;

    while (root) {
        TreeNode** next_node = nullptr;

        if (root->val < val)
            next_node = &root->right;
        else {
            next_node = &root->left;
        }

        if (!(*next_node)) {
            *next_node = new_node;
            break;
        }

        root = *next_node;
    }

    return ret_root;
}

SOLVE()
{
    TreeNode* root = new TreeNode(1);
    insertIntoBST(root, 1);
}

}
