#pragma once

// 2. You are given two non-empty linked lists representing two non-negative integers.
//    The digits are stored in reverse order, and each of their nodes contains a single
//    digit. Add the two numbers and return the sum as a linked list.

// Solution: (complexity O(N))
// Add current nodes values, add carry if present,
// check if they overflow a decimal digit, set carry
// if they do, set current node to the digit.

SOLUTION_FOR_PROBLEM(2, "Add Two Numbers") {

ListNode* addTwoNumbers(ListNode * l1, ListNode * l2) {
    ListNode* head = nullptr;
    ListNode* prev = nullptr;

    bool carry = false;

    while (l1 || l2) {
        int sum = 0;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        if (carry) {
            sum++;
            carry = false;
        }

        if (sum > 9) {
            carry = true;
            sum %= 10;
        }

        if (!head) {
            head = new ListNode(sum);
            prev = head;
        } else {
            prev->next = new ListNode(sum);
            prev = prev->next;
        }
    }

    if (carry)
        prev->next = new ListNode(1);

    return head;
}

SOLVE()
{
    auto l = make_list({ 2, 4, 3 });
    auto r = make_list({ 5, 6, 4 });

    auto res = addTwoNumbers(l, r);
}

}
