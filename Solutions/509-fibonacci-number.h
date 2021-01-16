#pragma once

#pragma once

// 509. Write a program to find the nth fibonacci number.

// Solution: (complexity O(log N))
// Using golden ration to our advantage, math is too complex to describe here.
// OR using a slower iterative O(N) approach where we keep track of N - 2 & N - 1 values and add them

namespace problem_509 {

    int fibonacci(int n)
    {
        static const auto sqrt_of_5 = sqrt(5);

        auto number = pow((1 + sqrt_of_5) / 2, n) - pow((1 - sqrt_of_5) / 2, n);

        return static_cast<int>(number / sqrt_of_5);
    }

    int slow_fibbonacci(int n)
    {
        if (n <= 1)
            return n;
        if (n == 2)
            return 1;

        int current = 0;
        int previous_1 = 1;
        int previous_2 = 1;

        for (int i = 3; i <= n; ++i) {
            current = previous_1 + previous_2;
            previous_1 = previous_2;
            previous_2 = current;
        }

        return current;
    }

}
