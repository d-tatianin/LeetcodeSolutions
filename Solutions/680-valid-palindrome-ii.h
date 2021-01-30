#pragma once

// 680. Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

// Solution: (complexity O(N))
// The base idea is the same as problem 125.
// The only difference is once we encounter a mismatch, we have a choice to delete either
// ith or jth character to fix our string. To find out which one would work (if any) we run
// isPalindrome on both [i + 1, j] and [i, j - 1] strings to see whether removing any of the
// mismatched characters would help.

SOLUTION_FOR_PROBLEM(680, "Valid Palindrome II") {

bool validPalindrome(std::string s) {
    auto is_palindrome = [](const std::string& s, size_t i, size_t j) -> bool {
        if (s.size() <= 1)
            return true;

        while (i < j) {
            if (tolower(s[i++]) != tolower(s[j--]))
                return false;
        }

        return true;
    };

    size_t i = 0;
    size_t j = s.size() - 1;

    while (i < j) {
        if (tolower(s[i]) != tolower(s[j])) {
            return is_palindrome(s, i + 1, j) || is_palindrome(s, i, j - 1);
        }

        i++;
        j--;
    }

    return true;
}


SOLVE()
{
    auto res = validPalindrome("abca");
}

}
