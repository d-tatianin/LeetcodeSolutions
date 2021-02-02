#pragma once

// 1190. You are given a string s that consists of lower case English letters and brackets. 
//       Reverse the strings in each pair of matching parentheses, starting from the innermost one.
//       Your result should not contain any brackets.

// Solution: (complexity O(N))
// First we generate paren pairs, such that pairs[opening_idx] -> closing_idx and pairs[closing_idx] -> opening_index
// After that we walk the array, starting forward and switching direction with each paren encounter.
// For each character in the string:
// - If it's an opening or closing paren, grab it's pair's index from the 'pairs' array and set it to i, reverse the stepping direction.
// - Otherwise just push the current character into the final string.

// For string (u(love)i)
// We do:
// Iteration 1: (u(love)i)
//              ^----------- paren hit, move to pair's index (paren after char 'i') and reverse stepping direction (now -1)
// Iteration 2: (u(love)i)
//                     ^----- paren hit, move to pair's index (paren after char 'u'), stepping direction is now +1
// Iteration 3: (u(love)i)
//                     ^----- paren hit (on the same paren as the last iteration!), this time stepping direction is -1 and we start at paren after char 'u' again
// Iteration 4: (u(love)i)
//              ^------------ parent hit, pair is paren after char 'i', with step direction +1 so as soon as we jump to it, we're out of the loop
// Done! with final string "iloveu"

SOLUTION_FOR_PROBLEM(1190, "Reverse Substrings Between Each Pair of Parentheses") {

std::string reverseParentheses(std::string str)
{
    std::stack<size_t> paren_indices;
    std::vector<size_t> pairs(str.size());

    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(')
            paren_indices.push(i);
        else if (str[i] == ')') {
            size_t opening_idx = paren_indices.top();
            paren_indices.pop();

            pairs[opening_idx] = i;
            pairs[i] = opening_idx;
        }
    }

    std::string out_string;
    out_string.reserve(str.size());

    int step = 1;
    for (size_t i = 0; i < str.size(); i += step) {
        if (str[i] == '(' || str[i] == ')') {
            i = pairs[i];
            step *= -1;
        } else {
            out_string += str[i];
        }
    }

    return out_string;
}

SOLVE()
{
    auto res = reverseParentheses("(u(love)i)");
}

}
