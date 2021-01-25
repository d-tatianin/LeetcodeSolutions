#pragma once

// 557. Given a string, you need to reverse the order of characters in each word within a sentence
//      while still preserving whitespace and initial word order.

// Solution: (complexity O(N))
// We keep to pointers:
// i -> pointer to current character
// j -> pointer to the beginning of current word
// Whenever we encounter a space we reverse the word at [j...i] and reset j with i + 1

SOLUTION_FOR_PROBLEM(557, "Reverse Words in a String III") {

std::string reverseWords(std::string s) {

    size_t i = 0;
    size_t j = 0;

    while (j < s.size())
    {
        if (isspace(s[i]) || i == s.size())
        {
            if (j != i)
                std::reverse(s.begin() + j, s.begin() + i);

            j = i + 1;
        }

        ++i;
    }

    return s;
}

SOLVE()
{
    auto reversed = reverseWords("Let's take LeetCode contest");
}

}
