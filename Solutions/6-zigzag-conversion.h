#pragma once

// 6. Description too long to fit here: https://leetcode.com/problems/zigzag-conversion/

// Solution: (complexity O(N))
// Create numRows buckets, iterate the string
// and append the current character to the bucket,
// increment the bucket iterator. Once we hit bottom or
// top of the bucket array, start going in the opposite direction.

SOLUTION_FOR_PROBLEM(6, "ZigZag Conversion") {

std::string convert(std::string s, int numRows) {
    if (numRows == 1 || numRows >= s.size())
        return s;

    int step = -1;
    size_t row = 0;

    std::vector<std::string> rows(numRows);

    for (char c : s) {
        rows[row] += c;

        if (row == 0 || row == static_cast<size_t>(numRows) - 1)
            step *= -1;

        row += step;
    }

    std::string ans;
    ans.reserve(s.size());

    for (auto& str : rows)
        ans += str;

    return ans;
}

SOLVE()
{
    auto res = convert("PAYPALISHIRING", 3);
}

}
