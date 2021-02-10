#pragma once

// 102. Given a binary tree, return the level order traversal of its nodes' values.
//      (ie, from left to right, level by level).

// Solution: (complexity O(N))
// Basic level order traversal using a queue.
// The only catch is that we have to remember queue size
// before traversing the current level so that we only emplace
// nodes that actually belong to current level into current array.

SOLUTION_FOR_PROBLEM(102, "Binary Tree Level Order Traversal") {

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    if (!root)
        return {};

    std::queue<TreeNode*> nodes;
    nodes.push(root);

    std::vector<std::vector<int>> out;

    while (!nodes.empty()) {
        size_t count = nodes.size();
        out.emplace_back();

        while (count-- > 0) {
            auto* top = nodes.front();
            nodes.pop();

            out.back().push_back(top->val);

            if (top->left)
                nodes.push(top->left);
            if (top->right)
                nodes.push(top->right);
        }
    }

    return out;
}

SOLVE()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    auto res = levelOrder(root);
}

}
