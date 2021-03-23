#pragma once

// 27. Given an array nums and a value val, remove all instances of that value in-place and return the new length.

// Solution: (complexity O(N))
// Shift all non-matching elements to the left, then resize
// the array to the number of shifted elements.

SOLUTION_FOR_PROBLEM(27, "Remove Element") {

int removeElement(std::vector<int>& nums, int val) {
    size_t j = 0;

    for (auto num : nums) {
        if (num != val)
            nums[j++] = num;
    }

    nums.resize(j);
    return static_cast<int>(j);
}

SOLVE()
{
    std::vector<int> vec = { 1, 3, 3, 2, 3, 5, 6 };
    auto res = removeElement(vec, 3);
}

}
