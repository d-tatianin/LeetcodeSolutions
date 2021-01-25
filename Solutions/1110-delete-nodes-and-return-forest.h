#pragma once

// 1110. Given the root of a binary tree, each node in the tree has a distinct value.
//       After deleting all nodes with a value in to_delete, we are left with a forest(a disjoint union of trees).
//       Return the roots of the trees in the remaining forest.You may return the result in any order.

// Solution: (complexity O(N))
// Basic postorder traversal with an extra array

SOLUTION_FOR_PROBLEM(1110, "Delete Nodes And Return Forest") {

inline void delete_all(TreeNode*& root, std::unordered_set<int>& numbers, std::vector<TreeNode*>& out)
{
    if (!root)
        return;

    delete_all(root->left, numbers, out);
    delete_all(root->right, numbers, out);

    if (numbers.count(root->val)) {
        if (root->left)
            out.emplace_back(root->left);
        if (root->right)
            out.emplace_back(root->right);

        root = nullptr;
        delete root;
    }
}

inline std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete) {

    std::unordered_set<int> set;
    for (auto x : to_delete)
        set.emplace(x);

    std::vector<TreeNode*> out_nodes;

    delete_all(root, set, out_nodes);

    if (root)
        out_nodes.emplace_back(root);

    return out_nodes;
}

SOLVE()
{
    TreeNode* r = new TreeNode(1);
    TreeNode* l = new TreeNode(2);
    TreeNode* ll = new TreeNode(3);

    r->left = l;
    l->left = ll;

    std::vector<int> vec = { 2 };

    auto res = delNodes(r, vec);
}

}
