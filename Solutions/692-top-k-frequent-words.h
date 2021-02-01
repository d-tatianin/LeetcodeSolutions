#pragma once

#include <queue>

// 692. Given a non-empty list of words, return the k most frequent elements.

// Solution: (complexity O(N Log K))
// Description of the solution goes here...

SOLUTION_FOR_PROBLEM(692, "Top K Frequent Words") {

std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
    std::unordered_map<std::string, size_t> str_to_occurences;

    for (auto& w : words)
        str_to_occurences[w]++;

    auto comparator =
        [&str_to_occurences](const std::string& l, const std::string& r)
    {
        auto l_occurences = str_to_occurences[l];
        auto r_occurences = str_to_occurences[r];

        return l_occurences == r_occurences ? l < r : l_occurences > r_occurences;
    };

    std::priority_queue<std::string, std::vector<std::string>, decltype(comparator)> pq(comparator);

    for (auto& w : str_to_occurences) {
        pq.emplace(w.first);

        if (pq.size() == static_cast<size_t>(k + 1))
            pq.pop();
    }

    std::vector<std::string> out(k);

    for (size_t i = k; i-- > 0;) {
        out[i] = pq.top();
        pq.pop();
    }

    return out;
}

SOLVE()
{
    std::vector<std::string> words = { "i", "love", "leetcode", "i", "love", "coding" };
    auto res = topKFrequent(words, 2);
}

}
