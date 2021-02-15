#pragma once

// 374. Description too long to fit here https://leetcode.com/problems/guess-number-higher-or-lower/

// Solution: (complexity O(Log N))
// Basic binary search.

SOLUTION_FOR_PROBLEM(374, "Guess Number Higher or Lower") {

int guess(int x)
{
    if (x < 10)
        return -1;
    if (x > 10)
        return 1;

    return 0;
}

int guessNumber(int n) {
    int begin = 1;
    int end = n;

    while (begin <= end) {
        auto middle = begin + (end - begin) / 2;

        auto res = guess(middle);

        if (res == 0)
            return middle;
        else if (res == -1)
            end = middle - 1;
        else
            begin = middle + 1;
    }

    return -1;
}

SOLVE()
{
    auto res = guessNumber(20);
}

}
