#pragma once

// 605. You have a long flowerbed in which some of the plots are planted, and some are not.
//      However, flowers cannot be planted in adjacent plots.
//      Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n,
//      return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

// Solution: (complexity O(N))
// For each plot:
// If i - 1, i, and i + 1 are all empty we can place a flower at i. Increment planted, and mark i as planted.
// If planted becomes equal to n, we managed to plant all necessary flowers, so return true.

SOLUTION_FOR_PROBLEM(605, "Can Place Flowers") {

bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    bool previous_empty = true;
    int planted = 0;

    for (size_t i = 0; i < flowerbed.size(); ++i) {
        bool next_empty = i < flowerbed.size() - 1 ? !flowerbed[i + 1] : true;

        if (previous_empty && !flowerbed[i] && next_empty) {
            planted += 1;
            flowerbed[i] = 1;
        }

        previous_empty = !flowerbed[i];

        if (planted >= n)
            return true;
    }

    return false;
}

SOLVE()
{
    std::vector<int> vec = { 1, 0, 0, 0, 1 };
    auto res = canPlaceFlowers(vec, 1);
}

}
