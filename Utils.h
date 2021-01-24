#pragma once

#include <initializer_list>
#include <ctime>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct Node {
    int   val;
    Node* left;
    Node* right;
    Node* next;
};

ListNode* make_list(std::initializer_list<int> numbers)
{

    ListNode* head = nullptr;
    ListNode* curr = nullptr;

    for (auto n : numbers) {
        if (!head) {
            head = new ListNode(n);
            curr = head;
            continue;
        }

        curr->next = new ListNode(n);
        curr = curr->next;
    }

    return head;
}

#define PROBLEM(problem_number, problem_name)        \
    namespace problem_##problem_number {             \
        static const char* name = problem_name;      \
        static const size_t number = problem_number; \
    }                                                \
    namespace problem_##problem_number

#define TRY_SOLVE() void try_solve()
