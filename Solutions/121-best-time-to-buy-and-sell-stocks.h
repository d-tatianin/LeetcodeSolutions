#pragma once

// 121. You are given an array prices where prices[i] is the price of a given stock on the ith day.
//      You want to maximize your profit by choosing a single day to buy one stockand choosing a
//      different day in the future to sell that stock. Return the maximum profit you can achieve
//      from this transaction.If you cannot achieve any profit, return 0.

// Solution: (complexity O(N))
// For each price:
// - if it's less than minimum seen, record it.
// - Calculate the profit we would get by selling the difference
//   between the current minimum and this price.
// - If it's the biggest so far, record it.

SOLUTION_FOR_PROBLEM(121, "Best Time to Buy and Sell Stock") {

int maxProfit(std::vector<int>& prices) {
    int current_min = INT_MAX;
    int max_profit = 0;

    for (auto p : prices) {
        current_min = std::min(current_min, p);
        max_profit = std::max(max_profit, p - current_min);
    }

    return max_profit;
}

SOLVE()
{
    std::vector<int> vec = { 7, 1, 5, 3, 6, 4 };
    auto res = maxProfit(vec);
}

}
