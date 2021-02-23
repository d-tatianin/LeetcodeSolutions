#pragma once

// 1038. Given the root of a Binary Search Tree (BST), convert it to a Greater Tree
//       such that every key of the original BST is changed to the original key plus
//       sum of all keys greater than the original key in BST.

// Solution: (complexity O(N))
// Basic idea is the sum of any given node is the sum of its right subtree +
// the sum of all nodes from its parent (if it's on the left).
// So all we have to do is perform a reverse inorder traversal and
// calculate those values.

SOLUTION_FOR_PROBLEM(1038, "Binary Search Tree to Greater Sum Tree") {

int do_count(int value_of_parent, TreeNode* self)
{
    if (!self)
        return 0;

    auto self_old = self->val;

    auto rhs = do_count(value_of_parent, self->right);
    self->val += value_of_parent + rhs;

    auto lhs = do_count(self->val, self->left);

    return lhs + rhs + self_old;
}

TreeNode* bstToGst(TreeNode* root) {
    do_count(0, root);

    return root;
}

SOLVE()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);

    root = bstToGst(root);
}

}
