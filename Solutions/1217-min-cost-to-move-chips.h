#pragma once

// 1217. Description too long to fit here https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/

// Solution: (complexity O(N))
// The idea here is that chips at odd positions
// will end up at position 1 and even chips will end up at position 0
// after moving both as close to 0 as possible for free.
// After that all we have to decide is whether we want to move
// evens to position 1 or odds to position 0. We decide that by picking
// the minimum between two coin counts.

SOLUTION_FOR_PROBLEM(1217, "Minimum Cost to Move Chips to The Same Position") {

int minCostToMoveChips(std::vector<int>& position) {
    int odd = 0;
    int even = 0;

    for (auto p : position) {
        auto rem = p % 2;
        odd += rem;
        even += !rem;
    }

    return std::min(odd, even);
}

SOLVE()
{
    std::vector<int> vec = { 1, 2, 3 };
    auto res = minCostToMoveChips(vec);
}

}
