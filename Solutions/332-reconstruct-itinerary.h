#pragma once

// 332. Given a list of airline tickets represented by pairs of departure and arrival airports [from, to],
//      reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK.
//      Thus, the itinerary must begin with JFK.

// Solution: (complexity O(N^2))
// Description of the solution goes here...

SOLUTION_FOR_PROBLEM(332, "Reconstruct Itinerary") {

using graph_t = std::unordered_map<std::string, std::multiset<std::string>>;

void fly(const std::string & port, graph_t& graph, std::vector<std::string>&answer)
{
    auto& destinations = graph[port];

    while (!destinations.empty()) {
        auto dest = *destinations.begin();
        destinations.erase(destinations.begin());
        fly(dest, graph, answer);
    }

    answer.push_back(port);
}

std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
    graph_t graph;
    std::vector<std::string> answer;

    for (const auto& ticket : tickets)
        graph[ticket[0]].emplace(ticket[1]);

    fly("JFK", graph, answer);
    std::reverse(answer.begin(), answer.end());

    return answer;
}

SOLVE()
{
    std::vector<std::vector<std::string>> vec = {
        {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}
    };

    auto res = findItinerary(vec);
}

}
