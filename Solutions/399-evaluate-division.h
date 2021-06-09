#pragma once

// 399. Description too long to fit here: https://leetcode.com/problems/evaluate-division/

// Solution: (complexity O(Q * (V + E)) (Q - queries, V - vertices, E - edges))
// -----------------------------------------------
// The important thing to note here is that if :
//  X         Y              X
// --- == Z, --- == V  then --- is equal Z * V
//  Y         C              C
// -----------------------------------------------
// And that:
//  X              Y            1
// --- == Z, then --- is equal ---
//  Y              X            Z
// -----------------------------------------------
// If you know these two rules it becomes a rather simple graph
// problem. We first generate a graph of X -> [ Y -> VALUE, ... ].
// Then for each query we check if there's a direct relation for the
// two specific X and Y, and if there isn't we recursively check all
// the relations of X to see if any of them are connected to Y and if they are,
// we use rule 1 to calculate the division.

SOLUTION_FOR_PROBLEM(399, "Evaluate Division") {

using graph_t = std::unordered_map<std::string, std::unordered_map<std::string, double>>;

double do_dfs(const std::string& x, const std::string& y, const graph_t& graph, std::unordered_set<std::string>& visited)
{
    if (!graph.count(x) || !graph.count(y))
        return -1.0;

    if (x == y)
        return 1.0;

    if (graph.at(x).count(y))
        return graph.at(x).at(y);

    for (const auto& node : graph.at(x)) {
        if (visited.count(node.first))
            continue;

        visited.emplace(node.first);

        auto res = do_dfs(node.first, y, graph, visited);

        if (res >= 0.0)
            return res * node.second;
    }

    return -1.0;
}

std::vector<double> calcEquation(
    std::vector<std::vector<std::string>>& equations,
    std::vector<double>& values,
    std::vector<std::vector<std::string>>& queries
)
{
    graph_t graph;
    graph.reserve(equations.size());

    for (size_t i = 0; i < equations.size(); ++i) {
        auto& eq = equations[i];
        auto res = values[i];

        graph[eq[0]][eq[1]] = res;
        graph[eq[1]][eq[0]] = 1 / res;
    }

    std::vector<double> answer;
    answer.reserve(queries.size());

    for (auto& q : queries) {
        std::unordered_set<std::string> visited;
        answer.push_back(do_dfs(q[0], q[1], graph, visited));
    }

    return answer;
}

SOLVE()
{
    std::vector<std::vector<std::string>> equations = { { "a", "b" }, { "b", "c" } };
    std::vector<double> values = { 2.0, 3.0 };
    std::vector<std::vector<std::string>> queries = { { "a", "c" }, { "b", "a" }, { "a", "e" }, { "a", "a" }, {"x", "x"} };

    auto res = calcEquation(equations, values, queries);
}

}
