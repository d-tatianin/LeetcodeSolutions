#pragma once

// 504. Given an integer, return its base 7 string representation.

// Solution: (complexity O(N))
// Get the last digit, shift left, repeat
// until we shift off all the digits.

SOLUTION_FOR_PROBLEM(504, "Base 7") {

std::string convertToBase7(int num) {
    if (num == 0)
        return "0";

    std::string res;

    bool is_neg = num < 0;

    if (is_neg)
        num *= -1;

    while (num) {
        auto rem = num % 7;
        res += std::to_string(rem);

        num /= 7;
    }

    if (is_neg)
        res += "-";

    std::reverse(res.begin(), res.end());

    return res;
}

SOLVE()
{
    auto res = convertToBase7(123);
}

}
