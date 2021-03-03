#pragma once

// 236. Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// Solution: (complexity O(N))
// - Do a DFS to check whether any subtrees contain any of the given nodes,
//   increment count by 1 if a given DFS detected a node.
// - Increment count by 1 again if current node is one of p/q
// - If count ended up being >= 2, current node is an LCA, set answer to it.

SOLUTION_FOR_PROBLEM(236, "Lowest Common Ancestor of a Binary Tree") {

bool find_lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& answer)
{
    if (!root)
        return false;

    int count = 0;
    count += (root == p || root == q);
    count += find_lca(root->left, p, q, answer);
    count += find_lca(root->right, p, q, answer);

    if (count >= 2)
        answer = root;

    return count;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* answer = nullptr;
    find_lca(root, p, q, answer);
    return answer;
}

SOLVE()
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    auto res = lowestCommonAncestor(root, root->left, root->right);
}

}
