#pragma once

// 690. Description too long to put here: https://leetcode.com/problems/employee-importance/

// Solution: (complexity O(N))
// 1. BFS Solution (Iterative):
// - Generate a map of id -> Employee
// - Put the first employee in the queue.
// - While queue is not empty:
// -- Add queue front employee importance to total.
// -- Push all subordinates of front employee into queue.
// -- Remove the front employee from the queue.
// 2. DFS Solution (Recursive):
// - Generate a map of id -> Employee
// - Start the recursion on the main employee id.
// - Return the current employee importance + all recursively accumulated.

SOLUTION_FOR_PROBLEM(690, "Employee Importance") {

// Definition for Employee. (Leetcode)
class Employee {
public:
    int id;
    int importance;
    std::vector<int> subordinates;
};

// BFS
int getImportance(std::vector<Employee*> employees, int id) {
    std::unordered_map<int, Employee*> id_to_employee;

    for (auto e : employees)
        id_to_employee[e->id] = e;

    int total = 0;
    std::queue<Employee*> subordinates;
    subordinates.push(id_to_employee[id]);

    while (!subordinates.empty()) {
        auto* employee = subordinates.front();
        subordinates.pop();

        total += employee->importance;

        for (auto sub : employee->subordinates)
            subordinates.push(id_to_employee[sub]);
    }

    return total;
}

int dfs(Employee* e, std::unordered_map<int, Employee*>& map)
{
    auto total = 0;

    for (auto sub : e->subordinates)
        total += dfs(map[sub], map);

    return total + e->importance;
}

int getImportanceDFS(std::vector<Employee*> employees, int id) {
    std::unordered_map<int, Employee*> id_to_employee;

    for (auto e : employees)
        id_to_employee[e->id] = e;

    return dfs(id_to_employee[id], id_to_employee);
}

SOLVE()
{
    std::vector<Employee*> vec = { new Employee{ 1, 2, { 3 } }, new Employee { 3, 1, {} } };

    auto res = getImportance(vec, 1);
    auto res1 = getImportanceDFS(vec, 1);
}

}
