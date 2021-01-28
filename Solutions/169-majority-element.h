#pragma once

// 169. Given an array nums of size n, return the majority element.
//      The majority element is the element that appears more than n / 2 times
//      You may assume that the majority element always exists in the array.

// Solution: (complexity O(N))
// Boyer-Moore Voting Algorithm
// For each number:
// If votes == 0 we set majority to this number and increment votes.
// Otherwise we decrement votes if number != majority or increment otherwise.

SOLUTION_FOR_PROBLEM(169, "Majority Element") {

int majorityElement(std::vector<int>& nums) {
    int majority_element = 0;
    int votes = 0;

    for (auto num : nums) {
        if (votes == 0)
            majority_element = num;

        votes += num == majority_element ? 1 : -1;
    }

    return majority_element;
}

SOLVE()
{
    std::vector<int> vec = { 2, 2, 1, 1, 1, 2, 2 };
    auto res = majorityElement(vec);
}

}
