#pragma once

// 937. Description is too long to be put here, read it here: https://leetcode.com/problems/reorder-data-in-log-files/

// Solution: (complexity O(M * N Log N)) where M is the maximum length of a log
// We first use stable_partition to put all word logs before all digit logs,
// after that all we have to do is run a normal sort that compares all letter
// logs according to the problem rules.

SOLUTION_FOR_PROBLEM(937, "Reorder Data in Log Files") {

std::vector<std::string> reorderLogFiles(std::vector<std::string>& logs) {
    auto parition_itr = std::stable_partition(logs.begin(), logs.end(),
        [](const std::string& str) {
            return isalpha(str[str.find_first_of(" ") + 1]);
        });

    std::sort(logs.begin(), parition_itr,
        [](const std::string& l, const std::string& r)
        {
            auto l_begin = l.find_first_of(" ");
            auto r_begin = r.find_first_of(" ");

            auto l_pure = std::string_view(l.data() + l_begin + 1, l.size() - l_begin - 1);
            auto r_pure = std::string_view(r.data() + r_begin + 1, r.size() - r_begin - 1);

            if (l_pure == r_pure)
                return l < r;
            else
                return l_pure < r_pure;
        });

    return logs;
}

SOLVE()
{
    std::vector<std::string> vec = { "dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero" };

    auto res = reorderLogFiles(vec);
}

}
