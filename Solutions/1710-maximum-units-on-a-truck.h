#pragma once

// 1710. Too long to fit here: https://leetcode.com/problems/maximum-units-on-a-truck/

// Solution: (complexity O(N Log N))
// Just sort the boxes by amount, and subtract starting from biggest heap
// until the truck is empty.

SOLUTION_FOR_PROBLEM(1710, "Maximum Units on a Truck") {

int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {
    std::sort(boxTypes.begin(), boxTypes.end(), [](const auto& l, const auto& r) { return l[1] > r[1]; });

    int total = 0;

    for (const auto& type : boxTypes) {
        int boxes = std::min(truckSize, type[0]);

        total += boxes * type[1];
        truckSize -= boxes;

        if (truckSize == 0)
            break;
    }

    return total;
}

SOLVE()
{
    std::vector<std::vector<int>> vec = { {1, 3}, {2, 2}, {3, 1} };
    auto res = maximumUnits(vec, 4);
}

}
