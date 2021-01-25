#pragma once

// 24. Given a linked list, swap every two adjacent nodes and return its head.

// Solution: (complexity O(N))
// We swap each two elements by doing left->next = right->next, right->next = left
// The only complication is that we need to also change the ->next pointer
// of the node that was on the left of left pre-swap. This could be trivially solved
// by keeping a pointer to the previous node, however, the previous node for head doesn't exist.
// We could work around that case by either introducing an if check, or simply keeping a pointer to
// the `->next` member of previous node, or, in case of head - to the head pointer itself.

SOLUTION_FOR_PROBLEM(24, "Swap Nodes in Pairs") {

ListNode* swapPairs(ListNode * head) {
    if (!head)
        return head;
    
    // ->next member of the left->previous, or the head pointer itself for head
    auto** pre_left_next_pointer = &head;
    auto* left = head;
    auto* right = head->next;

    while (left && right) {
        left->next = right->next;
        right->next = left;

        *pre_left_next_pointer = right;
        pre_left_next_pointer = &left->next;


        if (!left->next)
            break;

        left = left->next;
        right = left->next;
    }

    return head;
}


SOLVE()
{
    auto list = make_list({ 1, 2, 3, 4 });

    auto res = swapPairs(list);
}

}
