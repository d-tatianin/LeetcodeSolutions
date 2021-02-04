#pragma once

// 617. Given two binary trees and imagine that when you put one of them to cover the other, some nodes of
//      the two trees are overlapped while the others are not. You need to merge them into a new binary tree.
//      The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node.
//      Otherwise, the NOT null node will be used as the node of new tree.

// Solution: (complexity O(N))
// If left node is null we return right.
// If right is null we return left.
// If we got this far, both nodes are not null, so we add the right's value to left.
// Then we call the same function with left of left and left of right and assign the result to left of left.
// Same thing for the right node. That way as soon as we encounter a null node we break out of the recursion,
// and the node we're assigning gets connected to the non-null subtree if such a subtree exists.

SOLUTION_FOR_PROBLEM(617, "Merge Two Binary Trees") {

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr)
        return t2;
    if (t2 == nullptr)
        return t1;

    t1->val += t2->val;

    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);

    return t1;
}

SOLVE()
{
    TreeNode l(1);
    TreeNode r(2);

    mergeTrees(&l, &r);
}

}
