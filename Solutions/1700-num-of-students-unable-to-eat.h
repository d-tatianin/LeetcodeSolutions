#pragma once

// 1700. Description too long to put here, https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

// Solution: (complexity O(N))
// Basic idea is that we first count the number of students that wanna eat sandwich 1,
// and the number of students that wanna eat sandwich 0. Once we have that, we start
// iterating the sandwiches, and decrement the demand counter for a specific sandwich by 1.
// Once the demand counter reaches 0 and we encounter a sandwich of that type again, we know
// for sure that no other student could ever take that sandwich, and thus the number of hungry
// students is currently equal to the demand counter for the opposite sandwich type.

SOLUTION_FOR_PROBLEM(1700, "Number of Students Unable to Eat Lunch") {

int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
    size_t demand_count_0 = 0;
    size_t demand_count_1 = 0;

    for (auto s : students) {
        demand_count_0 += !s;
        demand_count_1 += s;
    }

    for (auto s : sandwiches) {
        if (s == 0 && demand_count_0 == 0)
            return static_cast<int>(demand_count_1);
        if (s == 1 && demand_count_1 == 0)
            return static_cast<int>(demand_count_0);

        demand_count_0 -= !s;
        demand_count_1 -= s;
    }

    return 0;
}

SOLVE()
{
    std::vector<int> vec1 = { 1, 1, 0, 0 };
    std::vector<int> vec2 = { 1, 0, 1, 0 };

    auto res = countStudents(vec1, vec2);
}

}
