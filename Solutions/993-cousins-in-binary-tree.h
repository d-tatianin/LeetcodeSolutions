#pragma once

// 993. Return true if and only if the nodes corresponding to the values x and y are cousins.

// Solution: (complexity O(N))
// We do a level order traversal of the tree, while recording each
// node's parent before pushing it into the queue. The traversal is based
// on the technique used in the "Level Order Traversal" leetcode problem (size memorization)
// We then check the depth and parent of both nodes and return true if they have the same depth
// and different parents.

SOLUTION_FOR_PROBLEM(993, "Cousins in Binary Tree") {

std::pair<int, TreeNode*> depth_and_parent_of(int x, TreeNode * root)
{
    std::queue<std::pair<TreeNode*, TreeNode*>> nodes;
    nodes.push({ root, nullptr });
    int depth = 0;

    while (!nodes.empty()) {
        size_t count = nodes.size();
        depth++;

        while (count-- > 0) {
            auto node_info = nodes.front();
            nodes.pop();

            if (node_info.first->val == x)
                return { depth, node_info.second };

            if (node_info.first->left)
                nodes.push({ node_info.first->left, node_info.first });
            if (node_info.first->right)
                nodes.push({ node_info.first->right, node_info.first });
        }
    }

    return {};
}

bool isCousins(TreeNode * root, int x, int y) {
    auto l = depth_and_parent_of(x, root);
    auto r = depth_and_parent_of(y, root);

    return l.first == r.first && l.second != r.second;
}

SOLVE()
{
    TreeNode node(1);

    auto res = isCousins(&node, 1, 1);
}

}
