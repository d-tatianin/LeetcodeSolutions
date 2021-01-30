#pragma once

// 1200. Given an array of distinct integers arr, find all pairs of elements
//       with the minimum absolute difference of any two elements.

// Solution: (complexity O(N Log N))
// First we sort the array so that closest elements are next to each other.
// Then for each pair:
// - if difference between the two elements is less than the current minimum,
//   clear the array and set minimum to current difference.
// - if current difference is equal to minimum, add current pair into out array.

SOLUTION_FOR_PROBLEM(1200, "Minimum Absolute Difference") {

std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
    if (arr.size() < 2)
        return {};

    std::vector<std::vector<int>> out;

    std::sort(arr.begin(), arr.end());

    int min = INT_MAX;

    for (size_t i = 0; i < arr.size() - 1; ++i) {
        auto diff = arr[i + 1] - arr[i];

        if (diff < min) {
            min = diff;
            out.clear();
        }

        if (diff == min)
            out.push_back({ arr[i], arr[i + 1] });
    }

    return out;
}

SOLVE()
{
    std::vector<int> vec = { 4, 2, 1, 3 };

    auto res = minimumAbsDifference(vec);
}

}
