#pragma once

// 122. You are given an array prices where prices[i] is the price of a given stock on the ith day.
//      Find the maximum profit you can achieve.You may complete as many transactions as you like
//      (i.e., buy one and sell one share of the stock multiple times).

// Solution: (complexity O(N))
// Much simpler than it seems, just iterate the
// prices, and if the next price is greater than current,
// add their difference to the total profit.

SOLUTION_FOR_PROBLEM(122, "Best Time to Buy and Sell Stock II") {

int maxProfit(std::vector<int>& prices) {
    int profit = 0;

    for (size_t i = 0; i < prices.size() - 1; ++i) {
        if (prices[i] < prices[i + 1])
            profit += prices[i + 1] - prices[i];
    }

    return profit;
}

SOLVE()
{
    std::vector<int> vec = { 7, 1, 5, 3, 6, 4 };
    auto res = maxProfit(vec);
}

}
