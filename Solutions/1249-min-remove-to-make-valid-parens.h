#pragma once

// 1249. Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions )
//       so that the resulting parentheses string is valid and return any valid string.

// Solution: (complexity O(N))
// Walk the string and collect parens:
// - if it's an open paren, put it's position in the stack
// - if it's a close parent, pop an open paren if it exists, otherwise set current character to 'X'
// Now mark any remaining characters in open paren stack as 'X' because they don't have a related closing paren.
// Copy the current string to a new one ignoring all characters marked as X

SOLUTION_FOR_PROBLEM(1249, "Minimum Remove to Make Valid Parentheses") {

std::string minRemoveToMakeValid(std::string s) {
    std::stack<size_t> parens;

    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '(')
            parens.push(i);
        else if (s[i] == ')') {
            if (parens.empty())
                s[i] = 'X';
            else
                parens.pop();
        }

    }

    while (!parens.empty()) {
        s[parens.top()] = 'X';
        parens.pop();
    }

    std::string new_str;
    new_str.reserve(s.size());

    for (char c : s) {
        if (c == 'X')
            continue;

        new_str += c;
    }

    return new_str;
}

SOLVE()
{
    auto res = minRemoveToMakeValid("lee(t(c)o)de)");
}

}
