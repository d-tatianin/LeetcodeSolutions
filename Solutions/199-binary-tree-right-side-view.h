#pragma once

// 199. Given a binary tree, imagine yourself standing on the right side of it,
//      return the values of the nodes you can see ordered from top to bottom.

// Solution: (complexity O(N))
// Perform a level order traversal, recording the last element on each level.

SOLUTION_FOR_PROBLEM(199, "Binary Tree Right Side View") {

std::vector<int> rightSideView(TreeNode* root) {
    if (!root)
        return {};

    std::vector<int> out;

    std::queue<TreeNode*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        size_t count = nodes.size();

        while (count-- > 0) {
            auto* node = nodes.front();
            nodes.pop();

            if (count == 0)
                out.push_back(node->val);

            if (node->left)
                nodes.push(node->left);
            if (node->right)
                nodes.push(node->right);
        }
    }

    return out;
}

SOLVE()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    auto res = rightSideView(root);
}

}
