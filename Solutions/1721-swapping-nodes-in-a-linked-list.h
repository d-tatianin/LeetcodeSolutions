#pragma once

// 1721. You are given the head of a linked list, and an integer k.
//       Return the head of the linked list after swapping the values of the kth node
//       from the beginningand the kth node from the end(the list is 1 - indexed).

// Solution: (complexity O(N))
// First find the Kth node from the beginning of the list,
// Create two pointers, one pointing to kth node, and one pointing to head.
// Continue moving the two nodes forward until the kth node hits the tail,
// this is how we know our node that was pointing to head now points to N - Kth
// node. Finally just swap their values.

SOLUTION_FOR_PROBLEM(1721, "Swapping Nodes in a Linked List") {

ListNode* swapNodes(ListNode * head, int k) {
    auto* first = head;
    for (size_t i = 1; i < k; ++i)
        first = first->next;

    auto* new_tail = first;
    auto* new_head = head;

    while (new_tail->next != nullptr) {
        new_tail = new_tail->next;
        new_head = new_head->next;
    }

    std::swap(first->val, new_head->val);

    return head;
}

SOLVE()
{
    auto list = make_list({ 1, 2, 3, 4, 5 });
    list = swapNodes(list, 2);
}

}
