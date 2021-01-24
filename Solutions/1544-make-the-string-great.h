#pragma once

#include <string>

// 1544. Given a string s of lower and upper case English letters.
// A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
// - 0 <= i <= s.length - 2
// - s[i] is a lower - case letterand s[i + 1] is the same letter but in upper - case or vice - ver

// Solution: (complexity (O(N))
// Here we make use of stack to handle collapsing removal of adjacent characters.
// As an optimization to avoid std::reverse + copying contents of stack 1 by 1 we use std::string directly.
// for each character in the string:
// - If stack is empty, push the character and continue.
// - If stack top is equal to current character and is different case, we pop it, and skip current character.
// - Otherwise push current character on top of the stack.

PROBLEM(1544, "Make The String Great") {

std::string makeGood(const std::string& string) {
    if (string.size() <= 1)
        return string;

    auto is_bad_sequence = [](char l, char r) -> bool {
        if (tolower(l) != tolower(r))
            return false;

        return isupper(l) ^ isupper(r);
    };

    std::string stack;

    for (char c : string) {
        if (stack.empty() || !is_bad_sequence(stack.back(), c))
            stack.push_back(c);
        else
            stack.pop_back();
    }

    return stack;
}

TRY_SOLVE()
{
    auto res = makeGood("leEeetcode");
}

}
