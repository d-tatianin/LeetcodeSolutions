#pragma once

#include <vector>
#include <stack>
#include <utility>

// 739. Given a list of daily temperatures T, return a list such that, for each day in the input,
//      tells you how many days you would have to wait until a warmer temperature.
//      If there is no future day for which this is possible, put 0 instead.
// --------------------------------------------------------------
// Solution: (complexity O(N))
// Both solutions below are the same complexity
// --------------------------------------------------------------
// Solution 1 (probably the more expected one):
// For each number starting from the end:
// - While stack contains temperatues lower than current, pop all items
// - If stack ends up empty, there's no higher temperature in the array, so set out[i] to 0
// - Otherwise set out[i] to top of the stack index - i
// - Push current temperature -> index onto the stack
// --------------------------------------------------------------
// Solution 2 (a bit faster than the previous):
// For each number starting from the end:
// - Set pointer j to i + 1
// - While item at j is smaller than item at i:
// -- If out[j] is 0 that means there isn't a higher temperature than current, set j to T.size() as an indicator of failed search
// -- Otherwise increment j by that offset, that's the next biggest number
// - If j ended up less than T.size() it is the index that we're looking for, so set out[i] to j - i
// --------------------------------------------------------------

SOLUTION_FOR_PROBLEM(739, "Daily Temperatures") {

std::vector<int> dailyTemperatures(std::vector<int> & T) {
    std::stack<std::pair<int, size_t>> temp_to_idx;
    std::vector<int> out(T.size());


    for (size_t i = T.size(); i-- > 0;) {
        while (!temp_to_idx.empty() && temp_to_idx.top().first <= T[i])
            temp_to_idx.pop();

        out[i] = temp_to_idx.empty() ? 0 : static_cast<int>(temp_to_idx.top().second - i);

        temp_to_idx.push({ T[i], i });
    }

    return out;
}

std::vector<int> dailyTemperatures2(std::vector<int>& T) {
    std::vector<int> out(T.size());

    for (size_t i = T.size(); i-- > 0;)
    {
        auto j = i + 1;

        while (j < T.size() && T[j] <= T[i]) {
            if (out[j] == 0)
                j = T.size();
            else
                j += out[j];
        }

        if (j != T.size())
            out[i] = static_cast<int>(j - i);
    }

    return out;
}

SOLVE()
{
    std::vector<int> vec = { 73, 74, 75, 71, 69, 72, 76, 73 };

    auto res1 = dailyTemperatures(vec);
    auto res2 = dailyTemperatures2(vec);
}

}
