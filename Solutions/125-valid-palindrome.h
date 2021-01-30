#pragma once

#include <string>

// 125. Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// Solution: (complexity O(N))
// Create two pointers, one at index 0 and one at the last index (i and j)
// while i < j:
// if any of the characters are not letters/digits, skip them
// if they're not equal, it's not a valid palindrome, so return false

SOLUTION_FOR_PROBLEM(125, "Valid Palindrome") {

bool isPalindrome(std::string s) {
    if (s.size() <= 1)
        return true;

    size_t i = 0;
    size_t j = s.size() - 1;

    while (i < j) {
        if (!isalnum(s[i])) {
            i++;
            continue;
        }

        if (!isalnum(s[j])) {
            j--;
            continue;
        }

        if (tolower(s[i++]) != tolower(s[j--]))
            return false;
    }

    return true;
}


SOLVE()
{
    auto res = isPalindrome("A man, a plan, a canal: Panama");
}

}
