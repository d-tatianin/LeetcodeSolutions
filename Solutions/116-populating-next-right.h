#pragma once

// 116. Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Solution: (complexity O(N))
// For each level, for each node from left to right:
// - Link left child to right child, link right child to left child of the next node of current.
// - Switch to the next node of current.
// - If current doesn't have next, switch to the left child of the initial node of this level.

SOLUTION_FOR_PROBLEM(116, "Populating Next Right Pointers in Each Node") {

Node* connect(Node* root) {
    auto* current_root = root;

    while (current_root) {
        auto* this_level = current_root;

        while (this_level) {
            if (this_level->left)
                this_level->left->next = this_level->right;
            if (this_level->right && this_level->next)
                this_level->right->next = this_level->next->left;

            this_level = this_level->next;
        }

        current_root = current_root->left;
    }

    return root;
}

SOLVE()
{
    Node n  { 1 };
    Node n1 { 2 };
    Node n2 { 3 };

    n.left = &n1;
    n.right = &n2;

    connect(&n);
}

}
