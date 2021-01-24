#pragma once

#include <unordered_map>
#include <vector>

// 560. Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

// Solution: (complexity O(N))
// Here we make use of the formula that states that sum of elements array[L...R] = array[R] - array[L - 1].
// By L we mean any index in the array, that is less than R. By R we mean the current index of the array.
// For every given number in the array:
// - add the number to the total sum.
// - calculate the target [L - 1] value, subtraction of which from [R] would yield k.
// - if target [L - 1] had been seen before R, add the number of occurences of such [L - 1] to answer.
// - increment the number of occurences for current total sum by 1.

PROBLEM(560, "Subarray Sum Equals K") {

inline int subarraySum(const std::vector<int> numbers, int k)
{
    int total_sum = 0;
    int subarray_count = 0;

    std::unordered_map<int, int> sum_to_frequency;

    // 0 occured once at index -1, needed for cases where we find array[R] such that it is equal k,
    // otherwise we would skip the L == 0 case.
    sum_to_frequency[0] = 1;

    for (auto number : numbers) {
        total_sum += number;

        auto target = total_sum - k;

        if (sum_to_frequency.count(target))
            subarray_count += sum_to_frequency[target];

        sum_to_frequency[total_sum]++;
    }

    return subarray_count;
}

TRY_SOLVE()
{
    auto sum = subarraySum({ 1, 2, 3 }, 1);
}

}
