#pragma once

// 235. Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

// Solution: (complexity O(Log N))
// Since we know that we're dealing with a BST this makes our search
// pretty trivial. We know that if both nodes are less than current,
// they're both on the left, otherwise they're both on ther right.
// However, if e.g one is smaller than current and one is greater
// that would mean current *is* the LCA.

SOLUTION_FOR_PROBLEM(235, "Lowest Common Ancestor of a Binary Search Tree") {

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root)
        return nullptr;

    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return root;
}

SOLVE()
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    auto res = lowestCommonAncestor(root, root->left, root->right);
}

}
