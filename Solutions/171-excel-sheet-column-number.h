#pragma once

// 171. Given a column title as appear in an Excel sheet, return its corresponding column number.

// Solution: (complexity O(N))
// This is basically a question about converting a base 26 system into decimal.
// All we have to do is convert each letter to corresponding number (e.g 1 for A), while shifting previous total left by 1 position.
// Since left shift for 26 base system doesn't exist, we can emulate it by multiplying the current number by 26.

SOLUTION_FOR_PROBLEM(171, "Excel Sheet Column Number") {

int titleToNumber(std::string s) {
    int total = 0;

    for (char c : s) {
        total *= 26; // shift left by 1 position
        total += c - 'A' + 1;
    }

    return total;
}

SOLVE()
{
    auto res = titleToNumber("ZY");
}

}
