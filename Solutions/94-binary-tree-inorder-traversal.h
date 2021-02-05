#pragma once

// 94. Given the root of a binary tree, return the inorder traversal of its nodes' values.

// Solution: (complexity O(N))
// Trivial recursive solution: traverse left, push root, traverse right.

SOLUTION_FOR_PROBLEM(94, "Binary Tree Inorder Traversal") {

void do_traverse(TreeNode* root, std::vector<int>& vec)
{
    if (!root)
        return;

    do_traverse(root->left, vec);
    vec.push_back(root->val);
    do_traverse(root->right, vec);
}

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> out;

    do_traverse(root, out);

    return out;
}

SOLVE()
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    auto res = inorderTraversal(root);
}

}
