#pragma once

#include "297-serialize-and-deserialize-binary-tree.h"

// 114. Given the root of a binary tree, flatten the tree into a "linked list"

// Solution: (complexity O(N))
// For every node, going right each time:
// - If node has a left child, attach node's right child to the bottom of left child's right child.
// - Make the left child the right child.

SOLUTION_FOR_PROBLEM(114, "Flatten Binary Tree to Linked List") {

void flatten(TreeNode* root) {
    while (root) {
        if (root->left) {
            auto* pre = root->left;

            while (pre->right)
                pre = pre->right;

            pre->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

        root = root->right;
    }
}

SOLVE()
{
    Solution_297::Codec c;

    auto tree = c.deserialize("1,2,5,3,5,#,6");

    flatten(tree);
}

}
