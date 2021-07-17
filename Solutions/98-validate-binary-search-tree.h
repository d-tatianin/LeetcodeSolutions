#pragma once

// 98. Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// Solution: (complexity O(N))
// Iterate each node of the tree while setting the min and max constraints per node.
// For left hand side we set the upper limit constraint (at least parent - 1), for right
// hand side we set the lower limit constrant (at least parent + 1).

SOLUTION_FOR_PROBLEM(98, "Validate Binary Search Tree") {

bool isValidBST(TreeNode* root, long long min = INT_MIN, long long max = INT_MAX) {
    if (!root)
        return true;

    if (root->val < min || root->val > max)
        return false;

    return isValidBST(root->left, min, static_cast<long long>(root->val) - 1) &&
           isValidBST(root->right, static_cast<long long>(root->val) + 1, max);
}

SOLVE()
{
    TreeNode root(2);
    TreeNode left(1);
    TreeNode right(3);

    root.left = &left;
    root.right = &right;

    isValidBST(&root);
}

}
