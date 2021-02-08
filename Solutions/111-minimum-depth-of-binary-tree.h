#pragma once

// 111. Given a binary tree, find its minimum depth.

// Solution: (complexity O(N))
// Very basic recursive solution, where we add + 1 to the previous depth
// recursively and select the minimum between left and right subtrees.
// The only catch is that we have to not take null children's depth into
// account if we have another non-null child. We do this by taking a max()
// in case we have a null child, so that the non-null child always wins.

SOLUTION_FOR_PROBLEM(111, "Minimum Depth of Binary Tree") {

int minDepth(TreeNode* root) {
    if (!root)
        return 0;

    auto left_depth = minDepth(root->left);
    auto right_depth = minDepth(root->right);

    if (root->left && root->right)
        return 1 + std::min(left_depth, right_depth);

    return 1 + std::max(left_depth, right_depth);
}

SOLVE()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);

    auto res = minDepth(root);
}

}
