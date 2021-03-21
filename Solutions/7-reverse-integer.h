#pragma once

// 7. Given a signed 32-bit integer x, return x with its digits reversed.
//    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// Solution: (complexity O(Log N))
// Basic integer conversion where we get the remainder by taking the mod 10
// each time and dividing the original while multiplying the new one by 10.
// The only tricky part is we have to check whether the multiplication of the
// new integer would overflow.

SOLUTION_FOR_PROBLEM(7, "Reverse Integer") {

int reverse(int x) {
    int res = 0;

    constexpr auto max_divided_by_10 = INT_MAX / 10;
    constexpr auto min_divided_by_10 = INT_MIN / 10;

    while (x) {
        auto pop = x % 10;

        if (res > max_divided_by_10 || (res == max_divided_by_10 && pop > 7))
            return 0;
        if (res < min_divided_by_10 || (res == min_divided_by_10 && pop < -8))
            return 0;

        res *= 10;
        res += pop;
        x /= 10;
    }

    return res;
}

SOLVE()
{
    auto res = reverse(123);
}

}
