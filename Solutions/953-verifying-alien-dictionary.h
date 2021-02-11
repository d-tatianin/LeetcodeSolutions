#pragma once

// 953. Description too long to fit here https://leetcode.com/problems/verifying-an-alien-dictionary/

// Solution: (complexity O(N))
// Compute a map of char -> position in alphabet.
// Lexicographically compare words in order.

SOLUTION_FOR_PROBLEM(953, "ProblemName") {

bool isAlienSorted(std::vector<std::string>&words, std::string order) {
    if (words.size() < 2)
        return true;

    size_t alphabet[26]{};

    for (size_t i = 0; i < order.size(); ++i)
        alphabet[order[i] - 'a'] = i;

    for (size_t i = 1; i < words.size(); ++i) {
        size_t j = 0;
        size_t k = 0;
        size_t length = std::min(words[i].size(), words[i - 1].size());

        for (; j < length; ++j, ++k) {
            size_t l = alphabet[words[i - 1][j] - 'a'];
            size_t r = alphabet[words[i][k] - 'a'];

            if (r < k)
                return false;
            if (k < r)
                goto dont_check_size;
        }

        if (words[i - 1].size() > words[i].size())
            return false;

    dont_check_size:;
    }

    return true;
}

SOLVE()
{
    std::vector<std::string> vec = { "hello", "leetcode" };

    isAlienSorted(vec, "hlabcdefgijkmnopqrstuvwxyz");
}

}
