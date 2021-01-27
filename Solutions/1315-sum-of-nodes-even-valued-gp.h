#pragma once

// Using this for tests :)
#include "297-serialize-and-deserialize-binary-tree.h"

// 1315. Given a binary tree, return the sum of values of nodes with even-valued grandparent.

// Solution: (complexity O(N))
// Very simple recursion, with the only catch being propagating both parent and grandparent values.

SOLUTION_FOR_PROBLEM(1315, "Sum of Nodes with Even-Valued Grandparent") {

int sumEvenGrandparent(TreeNode * root, int parent_value = 1, int grandparent_value = 1) {
    if (!root)
        return 0;

    return sumEvenGrandparent(root->left, root->val, parent_value)  +
           sumEvenGrandparent(root->right, root->val, parent_value) +
           (grandparent_value % 2 ? 0 : root->val);
}

SOLVE()
{
    Solution_297::Codec c;
    auto* tree = c.deserialize("6,7,8,2,7,1,3,9,#,1,4,#,#,#,5");

    auto res = sumEvenGrandparent(tree);
}

}
