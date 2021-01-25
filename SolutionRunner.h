#pragma once

#include <initializer_list>
#include <ctime>
#include <string_view>
#include <iostream>
#include <map>

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

class LeetcodeSolution
{
public:
    std::string_view name() const { return m_name; }
    size_t number() const { return m_number; }

    virtual void run() = 0;

protected:
    LeetcodeSolution(size_t number, std::string_view name);

private:
    size_t m_number;
    std::string_view m_name;
};

#define SOLUTION_FOR_PROBLEM(problem_number, problem_name)                      \
    namespace Solution_##problem_number {                                       \
    class SpecificSolution : public LeetcodeSolution {                          \
    public:                                                                     \
        SpecificSolution() : LeetcodeSolution(problem_number, problem_name) {}  \
        void run() override;                                                    \
    } inline static solution; namespace                                         \

#define SOLVE() } void SpecificSolution::run()

class SolutionRunner {
public:
    static void register_self(LeetcodeSolution* soluton)
    {
        if (!s_solutions)
            s_solutions = new std::remove_pointer_t<decltype(s_solutions)>();

        (*s_solutions)[soluton->number()] = soluton;
    }

    static int run_all()
    {
        if (!s_solutions)
            return -1;

        for (auto& number_to_solution : *s_solutions) {
            auto& solution = *number_to_solution.second;

            std::cout << "Running solution for problem[" << solution.number() << "] " << solution.name() << std::endl;
            solution.run();
        }

        return 0;
    }

private:
    inline static std::map<size_t, LeetcodeSolution*>* s_solutions;
};

LeetcodeSolution::LeetcodeSolution(size_t number, std::string_view name)
    : m_number(number)
    , m_name(name)
{
    SolutionRunner::register_self(this);
}
