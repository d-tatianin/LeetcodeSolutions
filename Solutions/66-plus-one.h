#pragma once

// 66. Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

// Solution: (complexity (O(N))
// For each number in the array starting from end:
// - if number is equal to 9 set it to 0 and continue (emulating a carry)
// - otherwise increment number and we're done
// If carry reaches outside the array just push 1 as the first element turning 000 -> 1000

PROBLEM(66, "Plus One") {

inline std::vector<int> plusOne(std::vector<int>& digits) {
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        if (*it == 9) {
            *it = 0;
            continue;
        }

        *it += 1;
        return digits;
    }

    // If we get here all numbers in the array are 0
    // so we can afford to change first to 1 and then push back 0
    // over doing emplace(0, 1), which costs O(N)
    digits[0] = 1;
    digits.push_back(0);

    return digits;
}

TRY_SOLVE()
{
    std::vector<int> vec2 = { 9, 9, 9 };

    auto arr = plusOne(vec2);
}

}
