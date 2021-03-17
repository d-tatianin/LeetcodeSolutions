#pragma once

// 5. Given a string s, return the longest palindromic substring in s.

// Solution: (complexity O(N^2))
// Iterate the string and for each center I, check how long
// the palindrome starting at it's index is. If it's longer
// than the maximum so far, record it.

SOLUTION_FOR_PROBLEM(5, "Longest Palindromic Substring") {

std::string longestPalindrome(std::string s) {
    auto length_of_palindrome = [](const std::string& str, size_t left, size_t right)
    {
        while (left >= 0 && right < str.size() && str[left] == str[right]) {
            // to compensate for left since we can't make an unsigned number negative
            if (left == 0) {
                right += 2;
                break;
            }

            right++;
            left--;
        }

        return right - left - 1;
    };

    size_t begin = 0;
    size_t max_length = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        auto length1 = length_of_palindrome(s, i, i);
        auto length2 = length_of_palindrome(s, i, i + 1);

        auto bigger = std::max(length1, length2);

        if (bigger > max_length) {
            if (bigger % 2)
                begin = i - bigger / 2;
            else // Even length palindromes like ABBA have 2 centers so the starting index is offset right by 1
                begin = (i + 1) - bigger / 2;

            max_length = bigger;
        }
    }

    return s.substr(begin, max_length);
}

SOLVE()
{
    auto res = longestPalindrome("babad");
}

}
