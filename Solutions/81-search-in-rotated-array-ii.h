#pragma once

// 81. Same as #33 but this time we have duplicate elements.

// Solution: (complexity O(Log N))
// Since there are now duplicate elements we have to handle them in the
// first binary search loop. That's pretty much it.
// NOTE: The complexity can degrade to O(N) in worst case

SOLUTION_FOR_PROBLEM(81, "Search in Rotated Sorted Array II") {

int search(std::vector<int>& nums, int target) {
    if (nums.empty())
        return -1;

    int begin = 0;
    int end = static_cast<int>(nums.size() - 1);

    while (begin < end) {
        while (begin < end && nums[begin] == nums[begin + 1])
            begin++;
        while (begin < end && nums[end] == nums[end - 1])
            end--;

        auto middle = begin + (end - begin) / 2;

        if (nums[middle] > nums[end])
            begin = middle + 1;
        else
            end = middle;
    }

    if (target >= nums[begin] && target <= nums[nums.size() - 1])
        end = static_cast<int>(nums.size() - 1);
    else
        begin = 0;

    while (begin <= end) {
        auto middle = begin + (end - begin) / 2;

        if (nums[middle] == target)
            return true;
        else if (nums[middle] < target)
            begin = middle + 1;
        else
            end = middle - 1;
    }

    return false;
}

SOLVE()
{
    std::vector<int> vec = { 2, 5, 6, 0, 0, 1, 2 };
    auto res = search(vec, 0);
}

}
