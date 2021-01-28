#pragma once

// 986. You are given two lists of closed intervals, firstList and secondList,
//      where firstList[i] = [starti, endi] and secondList[j] = [startj, endj].
//      Each list of intervals is pairwise disjoint and in sorted order.
//      Return the intersection of these two interval lists.

// Solution: (complexity O(N + M))
// We solve this by using two pointers, one for firstList and another for secondList
// While there are lists to compare:
// - Compute the intersection between current lists
// - Add it into answer if it's a valid list (aka begin <= end)
// - Increment the pointer, which has a smaller end value, or increment both if ends are equal

SOLUTION_FOR_PROBLEM(986, "Interval List Intersections") {

std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>>& firstList, std::vector<std::vector<int>>& secondList) {
    std::vector<std::vector<int>> out;

    if (firstList.empty() || secondList.empty())
        return out;

    size_t i = 0;
    size_t j = 0;

    while (i < firstList.size() && j < secondList.size()) {
        std::vector<int> list(2);

        list[0] = std::max(firstList[i][0], secondList[j][0]);
        list[1] = std::min(firstList[i][1], secondList[j][1]);

        if (list[0] <= list[1])
            out.emplace_back(move(list));

        if (firstList[i][1] < secondList[j][1])
            i++;
        else if (secondList[j][1] < firstList[i][1])
            j++;
        else {
            i++;
            j++;
        }
    }

    return out;
}

SOLVE()
{
    std::vector<std::vector<int>> firstList = { {0, 2}, {5, 10}, {13, 23}, {24, 25} };
    std::vector<std::vector<int>> secondList = { {1, 5}, {8, 12}, {15, 24}, {25, 26} };

    auto res = intervalIntersection(firstList, secondList);
}

}
