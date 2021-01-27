#pragma once

// 33. You are given an integer array nums sorted in ascending order (with distinct values), and an integer target.
//     Suppose that nums is rotated at some pivot unknown to you beforehand
//     i.e., [0, 1, 2, 4, 5, 6, 7] might become[4, 5, 6, 7, 0, 1, 2]

// Solution: (complexity O(Log N))
// First we use a modified version of binary search to find the smallest number in the array,
// this number is located right after the rotated part of array.
// After we have the index of the smallest number we check whether our target lies on the left
// or the right side of the rotated array and set start & end accordingly.
// Finally we perform normal binary search on the correct side of the array.

SOLUTION_FOR_PROBLEM(33, "Search in Rotated Sorted Array") {

int search(std::vector<int>& nums, int target) {
    if (nums.empty())
        return -1;

    int begin = 0;
    int end = nums.size() - 1;

    while (begin < end) {
        auto middle = begin + (end - begin) / 2;

        if (nums[middle] > nums[end])
            begin = middle + 1;
        else
            end = middle;
    }

    if (target >= nums[begin] && target <= nums[nums.size() - 1])
        end = nums.size() - 1;
    else
        begin = 0;

    while (begin <= end) {
        auto middle = begin + (end - begin) / 2;

        if (nums[middle] == target)
            return middle;
        else if (nums[middle] < target)
            begin = middle + 1;
        else
            end = middle - 1;
    }

    return -1;
}

SOLVE()
{
    std::vector<int> vec = { 4, 5, 6, 7, 0, 1, 2 };

    auto res = search(vec, 0);
}

}
