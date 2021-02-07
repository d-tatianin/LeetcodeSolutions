#pragma once

// 322. You are given coins of different denominations and a total amount of money amount.
//      Write a function to compute the fewest number of coins that you need to make up that amount.

// Solution: (complexity O(M * N))
// The idea here is that we calcualte the minimum required coins for each
// sub-amount until we reach the total amount required. For each amount
// we subtract each coin if possible and pick the smallest amount of coins
// required to get a specific sub-amount, like amounts[i - coin].
// A good video with full explanation: https://www.youtube.com/watch?v=jgiZlGzXMBw

SOLUTION_FOR_PROBLEM(322, "Coin Change") {

int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> amounts(static_cast<size_t>(amount) + 1, INT_MAX);
    amounts[0] = 0;

    for (size_t i = 1; i <= amount; ++i) {
        for (auto coin : coins) {
            if (coin > i)
                continue;

            if (amounts[i - coin] == INT_MAX)
                continue;

            amounts[i] = std::min(amounts[i - coin] + 1, amounts[i]);
        }
    }

    return amounts[amount] == INT_MAX ? -1 : amounts[amount];
}

SOLVE()
{
    std::vector<int> vec = { 1, 2, 5 };
    auto res = coinChange(vec, 11);
}

}
