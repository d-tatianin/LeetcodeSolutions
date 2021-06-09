#pragma once

// 1010. You are given a list of songs where the ith song has a duration of time[i] seconds.
//       Return the number of pairs of songs for which their total duration in seconds is divisible by 60.
//       Formally, we want the number of indices i, j such that i < j with(time[i] + time[j]) % 60 == 0.

// Solution: (complexity O(N))
// Similar idea to 2sum, with a bit of complication on top.
// For each number in the array:
// - Calculate the value we would need to add to that number to make it divisible by 60.
// - If we've encounter such value before, add the count of occurences to answer.
// - Increment the count of occurences for the current remainder.

SOLUTION_FOR_PROBLEM(1010, "Pairs of Songs With Total Durations Divisible by 60") {

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

int numaPairsDivisibleBy60(const std::vector<int>& time) {
    int pairs = 0;
    std::unordered_map<int, size_t> r_to_count;

    for (size_t i = 0; i < time.size(); ++i) {
        auto remainder = time[i] % 60;

        if (remainder)
            remainder = 60 - remainder;

        pairs += r_to_count[remainder];
        r_to_count[remainder]++;
    }

    return pairs;
}

SOLVE()
{
    auto res = numPairsDivisibleBy60({ 30, 20, 150, 100, 40 });
    auto res1 = numaPairsDivisibleBy60({ 30, 20, 150, 100, 40 });
}

}
