#pragma once

// 35. Given a sorted array of distinct integers and a target value, return the index if the target is found.
//     If not, return the index where it would be if it were inserted in order.

// Solution: (complexity O(Log N))
// Classic binary search.

SOLUTION_FOR_PROBLEM(35, "Search Insert Position") {

int searchInsert(std::vector<int>& nums, int target) {
    if (nums.empty())
        return 0;

    int begin = 0;
    int end = static_cast<int>(nums.size()) - 1;

    while (begin <= end) {
        auto middle = begin + (end - begin) / 2;

        if (nums[middle] < target)
            begin = middle + 1;
        else if (target < nums[middle])
            end = middle - 1;
        else
            return middle;
    }

    return begin;
}

SOLVE()
{
    std::vector<int> vec = { 1, 2, 999, 99999 };
    auto res = searchInsert(vec, 3);
}

}
