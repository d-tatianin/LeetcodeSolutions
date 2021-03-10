#pragma once

// 938. Given the root node of a binary search tree, return the sum of values
//      of all nodes with a value in the range [low, high].

// Solution: (complexity O(N))
// Basic recursive DFS, since it's a BST we can afford to
// early return if value is less than or greater than bounds.

SOLUTION_FOR_PROBLEM(938, "Range Sum of BST") {

int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root)
        return 0;

    if (root->val < low)
        return rangeSumBST(root->right, low, high);
    if (root->val > high)
        return rangeSumBST(root->left, low, high);

    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

SOLVE()
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(99);

    auto res = rangeSumBST(root, 1, 50);
}

}
