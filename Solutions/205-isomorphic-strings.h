#pragma once

// 205. Given two strings s and t, determine if they are isomorphic.

// Solution: (complexity O(N))
// For each i (0...N):
// - if s[i] is already mapped to a character, make sure t[i] is that same character,
//   otherwise return false.
// - If t[i] is already mapped to some other character of s, return false.
//   Otherwise record the new mapping by marking t[i] as already mapped, and marking s[i] as mapped to t[i].

SOLUTION_FOR_PROBLEM(205, "Isomorphic Strings") {

bool isIsomorphic(std::string s, std::string t) {
    char s_char_to_t_char[128] {};
    bool mapped_t_chars[128] {};

    for (size_t i = 0; i < t.size(); ++i) {
        if (s_char_to_t_char[s[i]]) {
            if (s_char_to_t_char[s[i]] != t[i])
                return false;
        } else {
            if (mapped_t_chars[t[i]])
                return false;

            mapped_t_chars[t[i]] = true;
            s_char_to_t_char[s[i]] = t[i];
        }
    }

    return true;
}

SOLVE()
{
    auto res = isIsomorphic("egg", "add");
}

}
