#pragma once

// 1026. Given the root of a binary tree, find the maximum value V for which
//       there exist different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

// Solution: (complexity O(N))
// Recursively iterate the tree while keeping the current min and max.

SOLUTION_FOR_PROBLEM(1026, "Maximum Difference Between Node and Ancestor") {

int get_diff(TreeNode * root, int max, int min)
{
    if (!root)
        return max - min;

    max = std::max(root->val, max);
    min = std::min(root->val, min);

    auto left = get_diff(root->left, max, min);
    auto right = get_diff(root->right, max, min);

    return std::max(left, right);
}

int maxAncestorDiff(TreeNode* root) {
    if (!root)
        return 0;

    return get_diff(root, INT_MIN, INT_MAX);
}

SOLVE()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);

    auto res = maxAncestorDiff(root);
}

}
