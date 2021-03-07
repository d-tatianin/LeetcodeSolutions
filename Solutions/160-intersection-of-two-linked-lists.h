#pragma once

// 160. Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.

// Solution: (complexity O(N))
// Since both lists are guaranteed to only contain positive values
// we can inverse the sign of one list and if we find a negative value
// node on the second list that means we found our intersection.
// Then all we have to do is just inverse the values back and return that node.
// PS: As an alternative solution we could use an unordered set to store visited nodes,
// iterate list a, then iterate list b and check if we find already visited.

SOLUTION_FOR_PROBLEM(160, "Intersection of Two Linked Lists") {

void inverse(ListNode* head)
{
    while (head) {
        head->val *= -1;
        head = head->next;
    }
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    inverse(headA);

    auto* b = headB;
    while (b) {
        if (b->val < 0)
            break;

        b = b->next;
    }

    inverse(headA);

    return b;
}

SOLVE()
{
    auto* list = make_list({1, 2, 3});

    auto res = getIntersectionNode(list, list->next);


}

}
