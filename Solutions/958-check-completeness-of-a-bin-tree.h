#pragma once

#include "297-serialize-and-deserialize-binary-tree.h"

// Solution: (complexity O(N))
// Simple level order traversal, where we mark the moment when we first encounter
// a null node, and if we ever encounter a non-null node after that, the tree is incomplete.

SOLUTION_FOR_PROBLEM(958, "Check Completeness of a Binary Tree") {

bool isCompleteTree(TreeNode* root) {
    std::queue<TreeNode*> nodes;
    nodes.push(root);
    bool encountered_null = false;

    while (!nodes.empty()) {
        auto* node = nodes.front();
        nodes.pop();

        if (!node) {
            encountered_null = true;
            continue;
        }

        if (encountered_null)
            return false;

        nodes.push(node->left);
        nodes.push(node->right);
    }

    return true;
}

SOLVE()
{
    auto* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    auto res = isCompleteTree(root);
}

}
