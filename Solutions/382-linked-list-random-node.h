#pragma once

// 382. Given a singly linked list, return a random node's value from the linked list.

// Solution: (complexity O(N))
// We can either convert list to array, and pick a random index OR
// We can use reservoir sampling, which is considered the better solution here,
// so we're gonna use the latter.
// The algorithm is too long to explain here: https://en.wikipedia.org/wiki/Reservoir_sampling

SOLUTION_FOR_PROBLEM(382, "Linked List Random Node") {

class Solution {
public:
    Solution(ListNode* head)
        : head(head)
    {
    }

    int get_random() {
        int numbers_seen = 1;
        int final_pick = 0; // doesn't matter what we set this to, first number has a 100% chance of being picked
        auto* current_head = head;

        while (current_head) {
            auto should_pick = !(rand() % numbers_seen);

            if (should_pick)
                final_pick = current_head->val;

            current_head = current_head->next;

            ++numbers_seen;
        }

        return final_pick;
    }

private:
    ListNode* head;
};

SOLVE()
{
    auto list = make_list({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });

    Solution s(list);
    srand(static_cast<unsigned int>(time(nullptr)));

    auto r = s.get_random();
    r = s.get_random();
    r = s.get_random();
    r = s.get_random();
    r = s.get_random();
    r = s.get_random();
    r = s.get_random();
    r = s.get_random();
}

}
