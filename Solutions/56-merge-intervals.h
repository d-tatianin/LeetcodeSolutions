#pragma once

// 56. Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
//     and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Solution: (complexity O(log N))
// First we sort the ranges so that they're in increasing order.
// For each range:
// - If last_range.end() >= current_range.begin() means we have an overlap
//   we solve it by picking the maximum end of current & last ranges.
// - Otherwise emplace current_range and make it last_range.

SOLUTION_FOR_PROBLEM(56, "Merge Intervals") {

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    if (intervals.size() == 1)
        return intervals;

    std::sort(intervals.begin(), intervals.end(), [](auto& l, auto& r) { return l[0] < r[0]; });

    size_t i = 0;

    for (size_t j = 1; j < intervals.size(); ++j) {
        // range1 -------------->
        // range2           ------------>
        //                  ^ range1.end() > range2.begin()
        //
        // so we do this to fix the overlap:
        // merged ---------------------->

        if (intervals[i][1] >= intervals[j][0]) {
            intervals[i][1] = std::max(intervals[i][1], intervals[j][1]);
            continue;
        }

        intervals[++i] = intervals[j];
    }

    intervals.resize(i + 1);
    return intervals;
}

SOLVE()
{
    std::vector<std::vector<int>> v = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };

    auto merged = merge(v);
}

}
