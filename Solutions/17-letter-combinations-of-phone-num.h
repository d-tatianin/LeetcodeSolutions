#pragma once

// 17. Given a string containing digits from 2-9 inclusive, return all possible
//     letter combinations that the number could represent.

// Solution: (complexity O(3^N))
// Simple iterative solution where we iterate every character for every digit
// and append to the previous array of strings each time.

SOLUTION_FOR_PROBLEM(17, "Letter Combinations of a Phone Number") {

std::vector<std::string> letterCombinations(std::string digits) {
    if (digits.empty())
        return {};

    std::string_view mappings[9] = {
        "",     "abc", "def",
        "ghi",  "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    std::vector<std::string> ans{ "" };

    for (char d : digits) {
        std::vector<std::string> temp;

        for (char c : mappings[d - '0' - 1]) {
            for (auto& str : ans)
                temp.emplace_back(str + c);
        }

        ans = std::move(temp);
    }

    return ans;
}

SOLVE()
{
    auto res = letterCombinations("23");
}

}
