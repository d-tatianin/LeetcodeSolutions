#pragma once

// 973. Given an array of points where points[i] = [xi, yi] represents a point
//on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// Solution: (complexity O(N))
// Good old quick select.

SOLUTION_FOR_PROBLEM(973, "K Closest Points to Origin") {

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
    auto distance_to_0 = [](const auto& point)
    {
        // Distance between two points is sqrt((x1 - x2)^2 + (y1 - y2)^2)).
        // Since we're calculating the distance to 0 we can just add the squared x and y values.
        return point[0] * point[0] + point[1] * point[1];
    };

    std::nth_element(points.begin(), points.begin() + k, points.end(),
        [&](auto& l, auto& r)
        {
            return distance_to_0(l) < distance_to_0(r);
        });

    points.resize(k);
    return points;

}

SOLVE()
{
    std::vector<std::vector<int>> points = { { 1,3 }, { -2,2 } };;
    auto res = kClosest(points, 1);
}

}
