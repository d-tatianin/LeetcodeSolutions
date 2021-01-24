#pragma once

// 833. Description too long to fit here, just use this link: https://leetcode.com/problems/find-and-replace-in-string/

// Solution: (complexity O(N Log N + S))
// Sort the indexes so that they're in descending order. The reason why we do this
// is because if we go from bottom to top, indexes get skewed as we replace more characters.
// This isn't a problem if we start at the top though.
// After we sort, we do for each index:
// - Find the offset of source string in S.
// - If it's not equal to expected index then we're done with current index.
// - Otherwise we simply erase the substring we're replacing and then insert the target into its place.

PROBLEM(833, "Find And Replace in String") {

inline std::string findReplaceString(std::string& S, std::vector<int>& indexes, std::vector<std::string>& sources, std::vector<std::string>& targets) {
    std::vector<std::pair<int, int>> sorted;

    for (int i = 0; i < indexes.size(); ++i)
        sorted.emplace_back(indexes[i], i);

    std::sort(sorted.begin(), sorted.end(), [](auto& l, auto& r) { return l.first > r.first; });

    for (auto& elem : sorted) {
        auto pos = S.find(sources[elem.second].c_str(), elem.first, sources[elem.second].size());

        if (pos != elem.first)
            continue;

        S.erase(elem.first, sources[elem.second].size());
        S.insert(elem.first, targets[elem.second]);
    }

    return S;
}

TRY_SOLVE()
{
    std::string S = "abcd";
    std::vector<int> indexes = { 0, 2 };
    std::vector<std::string> sources = { "a", "cd" };
    std::vector<std::string> targets = { "eee", "ffff" };

    auto res = findReplaceString(S, indexes, sources, targets);
}

}
