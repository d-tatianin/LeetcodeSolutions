#pragma once

// 590. Given an n-ary tree, return the postorder traversal of its nodes' values.

// Solution: (complexity O(N))
// Very basic recursive postorder traversal, with the only twist being traversing
// each child from left to right in order.

SOLUTION_FOR_PROBLEM(590, "N-ary Tree Postorder Traversal") {

// Node from leetcode
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() : val(0) {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void do_postorder(Node* root, std::vector<int>& vec)
{
    if (!root)
        return;

    for (auto child : root->children)
        do_postorder(child, vec);

    vec.push_back(root->val);
}

std::vector<int> postorder(Node* root) {
    std::vector<int> out;

    do_postorder(root, out);

    return out;
}

SOLVE()
{
    Node n;
    n.children.push_back(new Node(1));
    n.children.push_back(new Node(2));

    auto res = postorder(&n);
}

}
