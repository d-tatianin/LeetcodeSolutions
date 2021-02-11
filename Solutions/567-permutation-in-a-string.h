#pragma once

// 567. Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
//      In other words, one of the first string's permutations is the substring of the second string.

// Solution: (complexity O(N + 26 * (N - M)))
// We generate a map of occurences of every character in the s1 string, and a similar map
// for the s2 string. For the s2 string, however, we treat this map as a sliding window,
// decrementing the first chracter of current window and incrementing the first of the next.
// If map1 ends up being equal to map2 at any point, s2 contains a permutation of s1.

SOLUTION_FOR_PROBLEM(567, "Permutation in String") {

bool checkInclusion(std::string s1, std::string s2) {
    if (s1.size() > s2.size())
        return false;

    std::vector<size_t> map1(26);
    std::vector<size_t> map2(26);

    for (size_t i = 0; i < s1.size(); ++i) {
        map1[s1[i] - static_cast<size_t>('a')]++;
        map2[s2[i] - static_cast<size_t>('a')]++;
    }

    for (size_t i = 0; i < (s2.size() - s1.size()); ++i) {
        if (map1 == map2)
            return true;

        map2[s2[i] - static_cast<size_t>('a')]--;
        map2[s2[i + s1.size()] - static_cast<size_t>('a')]++;
    }


    return map1 == map2;
}

SOLVE()
{
    auto res = checkInclusion("abc", "dcda");
}

}
