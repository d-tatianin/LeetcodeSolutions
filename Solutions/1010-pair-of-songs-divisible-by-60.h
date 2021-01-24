#pragma once

#include <vector>

// 1010. You are given a list of songs where the ith song has a duration of time[i] seconds.
//       Return the number of pairs of songs for which their total duration in seconds is divisible by 60.
//       Formally, we want the number of indices i, j such that i < j with(time[i] + time[j]) % 60 == 0.

// Solution: (complexity O(N))
// Similar idea to 2sum, with a bit of complication on top.
// For each number in the array:
// - Calculate the value we would need to add to that number to make it divisible by 60.
// - If we've encounter such value before, add the count of occurences to answer.
// - Increment the count of occurences for the current remainder.

PROBLEM(1010, "Pairs of Songs With Total Durations Divisible by 60") {

int numPairsDivisibleBy60(const std::vector<int>& time) {
    int remainder_to_frequency[60] {};
    int pair_count = 0;

    for (auto t : time) {
        auto remainder = t % 60;
        pair_count += remainder_to_frequency[remainder ? 60 - remainder : 0];
        remainder_to_frequency[remainder]++;
    }

    return pair_count;
}

TRY_SOLVE()
{
    auto res = numPairsDivisibleBy60({ 30, 20, 150, 100, 40 });
}

}
