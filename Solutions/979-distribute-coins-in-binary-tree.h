#pragma once

// 979. Too long to fit here: https://leetcode.com/problems/distribute-coins-in-binary-tree/

// Solution: (complexity O(N))
// Typical DFS solution where we keep a running total of coins available at each
// node to give or take. The main catch is that this running total *is* the number of steps.

SOLUTION_FOR_PROBLEM(979, "Distribute Coins in Binary Tree") {

int dfs(TreeNode* root, int& sum)
{
    if (!root)
        return 0;

    auto lhs = dfs(root->left, sum);
    auto rhs = dfs(root->right, sum);

    sum += std::abs(lhs);
    sum += std::abs(rhs);

    return lhs + rhs + root->val - 1;
}

int distributeCoins(TreeNode* root) {
    int sum = 0;
    dfs(root, sum);
    return sum;
}

SOLVE()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);

    auto res = distributeCoins(root);
}

}
