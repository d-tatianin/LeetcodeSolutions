#pragma once

// 387. Given a string, find the first non-repeating character in it and return its index.

// Solution: (complexity O(N))
// - Count number of occurences for each character.
// - Find the first index, which has a character with number of occurences == 1

SOLUTION_FOR_PROBLEM(387, "First Unique Character in a String") {

int firstUniqChar(std::string s) {
    int chars[26]{};

    for (char c : s)
        chars[c - 'a']++;

    for (size_t i = 0; i < s.size(); ++i) {
        if (chars[s[i] - 'a'] == 1)
            return static_cast<int>(i);
    }

    return -1;
}

SOLVE()
{
    auto res = firstUniqChar("loveleetcode");
}

}
