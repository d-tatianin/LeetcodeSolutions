#pragma once

// 8. Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

// Solution: (complexity O(N))
// Convert a digit to number, multiply result by 10, add the new digit to result.
// While doing that check for overflows and many othe edge cases along the way.

SOLUTION_FOR_PROBLEM(8, "ProblemName") {

int myAtoi(std::string s) {
    if (s.empty())
        return 0;

    size_t i = 0;

    while (i < s.size() && isspace(s[i]))
        i++;

    if (i == s.size())
        return 0;

    bool is_negative = false;
    if (s[i] == '-' || s[i] == '+') {
        is_negative = s[i++] == '-';
    }

    constexpr auto int_max_divided_by_10 = INT_MAX / 10;
    constexpr auto int_min_divided_by_10 = INT_MIN / 10;

    int result = 0;

    while (i < s.size() && isdigit(s[i])) {
        if (result == 0 && s[i] == '0') {
            i++;
            continue;
        }

        auto digit = s[i] - '0';
        if (is_negative)
            digit *= -1;

        if (result > int_max_divided_by_10 || (result == int_max_divided_by_10 && digit > 7))
            return INT_MAX;
        if (result < int_min_divided_by_10 || (result == int_min_divided_by_10 && digit < -8))
            return INT_MIN;

        result *= 10;
        result += digit;

        i++;
    }

    return result;
}

SOLVE()
{
    auto num = myAtoi("123");
}

}
