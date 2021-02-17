#pragma once

// 143. Given a singly linked list L: L0->L1->...->Ln-1->Ln,
//      reorder it to : L0->Ln->L1->Ln - 1->L2->Ln - 2->...

// Solution: (complexity O(N))
// 1. Collect all nodes into a double-ended queue.
// 2. Iterate the double ended queue from two ends, and push nodes
//    into a new array in order (left, right, left, right, ...).
// 3. Iterate the new array and relink nodes such array[i]->next = array[i + 1]

SOLUTION_FOR_PROBLEM(143, "Reorder List") {

void reorderList(ListNode* head) {
    if (!head)
        return;

    std::deque<ListNode*> list;

    while (head) {
        list.push_back(head);
        head = head->next;
    }

    std::vector<ListNode*> final_list;
    final_list.reserve(list.size());


    while (!list.empty()) {
        auto* left = list.front();
        auto* right = list.back();

        final_list.push_back(left);

        if (left != right) {
            final_list.push_back(right);
            list.pop_back();
        }

        list.pop_front();
    }

    for (size_t i = 0; i < final_list.size() - 1; ++i)
        final_list[i]->next = final_list[i + 1];

    final_list.back()->next = nullptr;
}

SOLVE()
{
    auto* list = make_list({ 1, 2, 3, 4 });
    reorderList(list);
}

}
