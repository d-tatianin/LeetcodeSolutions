#pragma once

#include <vector>
#include <unordered_set>

// 763. A string S of lowercase English letters is given. We want to partition this string into as many parts as possible
//      so that each letter appears in at most one part, and return a list of integers representing the size of these parts.


// Solution: (complexity O(N))
// Walk the array and count number of occurences for each character
// After that, for each char in the array:
// - Increment the seen characters counter by 1.
// - Record current character as blocking (aka preventing us from creating a subarray).
// - Decrement the count of occurences for current character.
// - If current character no longer occures in the array, remove it from blocking char set.
// - If blocking set is empty, record the current seen character count into vector, and reset the counter.

PROBLEM(763, "Partition Labels") {

std::vector<int> partitionLabels(std::string S) {
    int char_to_frequency[26]{};

    for (char c : S)
        char_to_frequency[c - 'a']++;

    std::unordered_set<char> blocking_chars;
    std::vector<int> answer;
    int count_for_this_subarray = 0;

    for (char c : S) {
        ++count_for_this_subarray;

        if (!blocking_chars.count(c))
            blocking_chars.emplace(c);

        if (--char_to_frequency[c - 'a'] == 0) {
            blocking_chars.erase(c);

            if (blocking_chars.empty()) {
                answer.push_back(count_for_this_subarray);
                count_for_this_subarray = 0;
            }
        }
    }

    return answer;
}

TRY_SOLVE()
{
    auto res = partitionLabels("ababcbacadefegdehijhklij");
}

}
