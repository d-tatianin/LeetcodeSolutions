#pragma once

// 939. Given a set of points in the xy-plane, determine the minimum area of a rectangle
//      formed from these points, with sides parallel to the x and y axes.

// Solution: (complexity O(N^2))
// The basic idea is that we want to find two points that are on the
// rectangle's diagonal.
// Generate a map of x -> all ys found for this x.
// Walk each pair for each pair:
// - if at least one coordinate matches, continue.
// - if ith point x doesnt contain jth point y, continue.
// - if jth point x doesnt contain ith point y, continue.
// - Otherwise calculate the area and record if it's less than minimum so far.

SOLUTION_FOR_PROBLEM(939, "Minimum Area Rectangle") {

int minAreaRect(std::vector<std::vector<int>>& points) {
    int ans = INT_MAX;
    std::unordered_map<int, std::set<int>> x_to_ys;

    for (auto& p : points)
        x_to_ys[p[0]].emplace(p[1]);

    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            if (points[i][0] == points[j][0] || points[i][1] == points[j][1])
                continue;

            if (x_to_ys[points[i][0]].count(points[j][1]) && x_to_ys[points[j][0]].count(points[i][1]))
                ans = std::min(ans, abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]));
        }
    }

    return ans == INT_MAX ? 0 : ans;
}

SOLVE()
{
    std::vector<std::vector<int>> vec = { {1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2} };
    auto res = minAreaRect(vec);
}

}
