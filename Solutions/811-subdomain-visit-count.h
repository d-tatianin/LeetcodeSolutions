#pragma once

// 811. Description too long to fit here: https://leetcode.com/problems/subdomain-visit-count/

// Solution: (complexity O(N * M))
// For each domain:
// - First we read the visit count of the current domain.
// - After that we iterate every string and each time we encounter a dot,
//   we increment the corresponding substring usage count in the map.

SOLUTION_FOR_PROBLEM(811, "Subdomain Visit Count") {

std::vector<std::string> subdomainVisits(std::vector<std::string>& cpdomains) {
    std::unordered_map<std::string, int> dom_to_count;

    for (auto& dom : cpdomains) {
        auto visits = atoi(dom.c_str());

        size_t i = 0;
        while (!isspace(dom[i]))
            ++i;
        ++i;

        dom_to_count[dom.substr(i)] += visits;

        for (; i < dom.size(); ++i) {
            if (dom[i] == '.') {
                dom_to_count[dom.substr(++i)] += visits;
            }
        }
    }

    std::vector<std::string> out;
    out.reserve(dom_to_count.size());

    for (auto& d : dom_to_count) {
        std::string res;
        res += std::to_string(d.second);
        res += " ";
        res += d.first;
        out.emplace_back(std::move(res));
    }

    return out;
}

SOLVE()
{
    std::vector<std::string> vec = { "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" };
    auto res = subdomainVisits(vec);
}

}
