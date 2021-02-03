#pragma once

// 203. Remove all elements from a linked list of integers that have value val.

// Solution: (complexity O(N))
// Simple recursive approach with two pointers to be able to relink the parent with new child.

SOLUTION_FOR_PROBLEM(203, "Remove Linked List Elements") {

ListNode* do_remove(ListNode* previous, ListNode* head, int val) {
    if (!head)
        return nullptr;

    if (head->val == val) {
        auto* next = head->next;

        if (previous)
            previous->next = next;

        delete head;

        return do_remove(previous, next, val);
    }

    do_remove(head, head->next, val);

    return head;
}

ListNode* removeElements(ListNode* head, int val) {
    return do_remove(nullptr, head, val);
}

SOLVE()
{
    auto* list = make_list({ 1, 2, 3, 3, 4, 3, 5 });
    removeElements(list, 3);
}

}
