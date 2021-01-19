#pragma once

#include <string>
#include <algorithm>
#include <unordered_map>

// 3. Given a string s, find the length of the longest substring without repeating characters.

// Solution: (complexity O(N))
// Make a start variable that marks the beginning of the current subarray, it starts at index -1,
// so that a subarray at index 0 has a length of 1, and not 0.
// For each character in the string:
// - If we've already seen this character before, reset the current index to the last seen position,
//   in case it's bigger than the start of current subarray.
// - Record the current character as seen at current index.
// - If current subarray is bigger than the biggest, record the new length.

namespace problem_3 {

inline int length_of_longest_substring(const std::string& s) {
    std::unordered_map<char, int> char_to_last_seen_index;
    int longest_subarray = 0;
    int start = -1;

    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];

        if (char_to_last_seen_index.count(c))
            start = std::max(start, char_to_last_seen_index[c]);

        char_to_last_seen_index[c] = i;
        longest_subarray = std::max(longest_subarray, i - start);
    }

    return longest_subarray;
}

}
