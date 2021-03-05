#pragma once

// 430. Flatten the list so that all the nodes appear in a single-level, doubly linked list.

// Solution: (complexity O(N))
// Basic DFS solution, use a stack to collect children.
// Pop an item off until the stack is empty, if item has a child, push it.

SOLUTION_FOR_PROBLEM(430, "Flatten a Multilevel Doubly Linked List") {

// Definition for a Node. (Leetcode)
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

Node* flatten(Node* head) {
    if (!head)
        return nullptr;

    Node* prev = nullptr;
    std::stack<Node*> parents;
    parents.push(head);

    while (!parents.empty())
    {
        auto* cur = parents.top();
        parents.pop();

        if (prev) {
            prev->next = cur;
            cur->prev = prev;
        }

        prev = cur;

        if (cur->next)
            parents.push(cur->next);

        if (cur->child)
            parents.push(cur->child);

        cur->child = nullptr;
    }

    return head;
}


SOLVE()
{
    Node root {};
    root.val = 1;

    Node child {};
    child.val = 2;

    root.child = &child;

    Node next{};
    next.val = 3;
    root.next = &next;

    auto res = flatten(&root);
}

}
