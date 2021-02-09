#pragma once

// 917. Given a string S, return the "reversed" string where all characters that are
//      not a letter stay in the same place, and all letters reverse their positions.

// Solution: (complexity O(N))
// We first push every character we encounter into the stack.
// After that we do a second pass of iterating the string, if we encounter a non-char
// we push it as is, otherwise we pop a char from the stack and add it to the answer string,
// thus reversing the characters.

SOLUTION_FOR_PROBLEM(917, "Reverse Only Letters") {

std::string reverseOnlyLetters(std::string S) {
    std::stack<char> str;

    for (char c : S) {
        if (!isalpha(c))
            continue;

        str.push(c);
    }

    std::string res;
    res.reserve(S.size());

    for (char c : S) {
        if (isalpha(c)) {
            res.push_back(str.top());
            str.pop();
        } else
            res.push_back(c);
    }

    return res;
}

SOLVE()
{
    auto res = reverseOnlyLetters("ab-cd");
}

}
