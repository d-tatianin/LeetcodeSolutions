#pragma once

// 49. Given an array of strings strs, group the anagrams together.

// Solution: (complexity O(N * M))
// For each string, generate a hash string in the form of:
// "# + number_of_occurences_of_a + # + number_of_occurences_of_b + ... + # + number_of_occurences_of_z"
// Use this hash string to append to an array of strings of the same hash in the map.

SOLUTION_FOR_PROBLEM(49, "Group Anagrams") {

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> map;

    for (auto& str : strs) {
        std::vector<int> table(26);

        for (char c : str)
            table[static_cast<size_t>(c) - 'a']++;

        std::string out;
        out.reserve(26 * 2);

        for (auto count : table) {
            out += '#';
            out += std::to_string(count);
        }

        map[out].push_back(str);
    }

    std::vector<std::vector<std::string>> out;
    out.reserve(map.size());

    for (auto& entry : map)
        out.emplace_back(std::move(entry.second));

    return out;
}

SOLVE()
{
    std::vector<std::string> vec = { "eat", "tea", "tan", "ate", "nat", "bat" };

    auto res = groupAnagrams(vec);
}

}
