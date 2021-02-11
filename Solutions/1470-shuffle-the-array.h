#pragma once

// 1470. Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
//       Return the array in the form[x1, y1, x2, y2, ..., xn, yn].

// Solution: (complexity O(N))
// Just iterate through the array and push ith and ith + n values.

SOLUTION_FOR_PROBLEM(1470, "Shuffle the Array") {

std::vector<int> shuffle(std::vector<int>& nums, int n) {

    std::vector<int> out;
    out.reserve(static_cast<size_t>(n) * 2);

    for (size_t i = 0; i < n; ++i) {
        out.push_back(nums[i]);
        out.push_back(nums[i + n]);
    }

    return out;
}

SOLVE()
{
    std::vector<int> vec = { 1, 2, 3, 4, 5, 6 };
    auto res = shuffle(vec, 3);
}

}
