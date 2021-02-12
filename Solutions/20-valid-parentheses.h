#pragma once

// 20. Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
//      determine if the input string is valid.

// Solution: (complexity O(N))
// Maintain a stack of opening parentheses, and check if they
// match when encountering a closing parent.

SOLUTION_FOR_PROBLEM(20, "Valid Parentheses") {

bool isValid(std::string s) {
    std::stack<char> parens;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[')
            parens.push(c);
        else {
            if (parens.empty()) {
                return false;
            } else if (c == ')' && parens.top() != '(') {
                return false;
            } else if (c == '}' && parens.top() != '{') {
                return false;
            } else if (c == ']' && parens.top() != '[') {
                return false;
            }

            parens.pop();
        }
    }

    return parens.empty();
}

SOLVE()
{
    auto res = isValid("(())");
}

}
