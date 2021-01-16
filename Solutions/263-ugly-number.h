#pragma once

// 263. Write a program to check whether a given number is an ugly number.

// Solution: (complexity O(log N))
// Very simple, just divide the number by 2, 3 and 5 as much as you can.
// If it is an ugly number you get 1 at the end.

namespace problem_263 {

inline bool is_ugly_number(int x)
{
    if (x < 1)
        return false;

    while (x % 5 == 0) x /= 5;
    while (x % 3 == 0) x /= 3;
    while (x % 2 == 0) x /= 2;

    return x == 1;
}

}
