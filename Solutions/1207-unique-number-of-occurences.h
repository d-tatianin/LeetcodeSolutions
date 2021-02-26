#pragma once

// 1207. Given an array of integers arr, write a function that returns true iff the number
//       of occurrences of each value in the array is unique.

// Solution: (complexity O(N))
// - Generate a map of number -> number of occurences.
// - Walk the map and store each number of occurences in a set,
//   if at any time we encounter an already seen (present in the set)
//   value we know it's not unique.

SOLUTION_FOR_PROBLEM(1207, "Unique Number of Occurrences") {

bool uniqueOccurrences(std::vector<int>& arr) {
    int occurences[2001]{};

    for (auto num : arr)
        occurences[num + 1000]++;

    std::unordered_set<int> unique;

    for (auto num : occurences) {
        if (!num)
            continue;

        if (unique.count(num))
            return false;

        unique.emplace(num);
    }

    return true;
}

SOLVE()
{
    std::vector<int> vec = { 1, 2, 2, 3, 3, 3 };
    auto res = uniqueOccurrences(vec);
}

}
