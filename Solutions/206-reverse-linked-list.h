#pragma once

// 206. Reverse a singly linked list.

// Solution: (complexity O(N))
// Basic recursion, which works like this:
// Imagine we have a list 1 -> 2 -> 3 -> 4
// recursion gets us to number 3, after which it starts to collapse into:
// 1 -> 2      4 -> 3 -> nullptr
//      |___________|
//
// 1      4 -> 3 -> 2 -> nullptr
// |________________|
//
//        4 -> 3 -> 2 -> 1 -> nullptr

SOLUTION_FOR_PROBLEM(206, "Reverse Linked List") {

ListNode* reverseList(ListNode * head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    auto new_head = reverseList(head->next);

    head->next->next = head;
    head->next = nullptr;

    return new_head;
}

SOLVE()
{
    auto list = make_list({ 1, 2, 3, 4 });
    auto res = reverseList(list);
}

}
