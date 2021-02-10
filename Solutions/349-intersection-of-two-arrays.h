#pragma once

// 349. Given two arrays, write a function to compute their intersection.

// Solution: (complexity O(N + M))
// First we create two sets that contain unique numbers from each array.
// After that we generate the intersection of said sets by iterating the longer
// set and checking if an element is present in the other (smaller) set.

SOLUTION_FOR_PROBLEM(349, "Intersection of Two Arrays") {

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> s1;
    std::unordered_set<int> s2;

    for (auto num : nums1)
        s1.emplace(num);
    for (auto num : nums2)
        s2.emplace(num);

    std::vector<int> out;

    auto* longer = s1.size() > s2.size() ? &s1 : &s2;
    auto* smaller = longer == &s1 ? &s2 : &s1;

    for (auto num : *longer) {
        if (smaller->count(num))
            out.push_back(num);
    }

    return out;
}

SOLVE()
{
    std::vector<int> vec1 = { 1, 999, -1 };
    std::vector<int> vec2 = { 999, 0, 1  };

    auto res = intersection(vec1, vec2);
}

}
