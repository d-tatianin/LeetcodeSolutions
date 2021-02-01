#pragma once

// 92. Reverse a linked list from position m to n. Do it in one-pass. (indexing starts at 1)

// Solution: (complexity O(N))
// Given list 1->2->3->4->5
// We want to find the position at which we start reversing, as well as the node before that.
// We save these two pointers because they will be needed later to fix the connections.
// Start swapping nodes by doing current->next = previous, and setting current to the old next
// of current, while decrementing N, and setting previous equal to current.
// After we're done swapping we restore the connections by setting the begin node's next to previous (last swapped).
// As well as restoring the correct connection for the first swapped node (since it was first swapped with 'prev' (aka node before pre-swap)

SOLUTION_FOR_PROBLEM(92, "Reverse Linked List II") {

ListNode* reverseBetween(ListNode * head, int m, int n) {
    if (!head)
        return nullptr;

    auto* current = head;
    ListNode* prev = nullptr;

    while (m > 1) {
        prev = current;
        current = current->next;

        --m;
        --n;
    }

    auto* begin = prev;
    auto* end = current;

    while (n) {
        auto* temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
        n--;
    }

    if (begin)
        begin->next = prev;
    else // list was sorted starting at index 1 so the head is now the last swapped node
        head = prev;

    end->next = current;

    return head;
}

SOLVE()
{
    auto* list = make_list({ 1, 2, 3, 4, 5 });

    auto res = reverseBetween(list, 2, 4);
}

}
