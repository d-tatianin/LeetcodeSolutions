#pragma once

// 313. Write a program to find the nth super ugly number.

// Solution: (complexity O(N*K))
// Identical idea to problem 264, just scaled up to fit K primes.

namespace problem_313 {

inline int nth_super_ugly_number(int n, const std::vector<int>& primes)
{
    if (n <= 0)
        return 0;

    if (n == 1)
        return 1;

    std::vector<int> ugly_numbers(n);
    std::vector<int> pointers(primes.size());
    ugly_numbers[0] = 1;

    for (int i = 1; i < n; ++i) {
        int next_ugly = INT_MAX;

        for (size_t j = 0; j < primes.size(); ++j)
            next_ugly = std::min(next_ugly, ugly_numbers[pointers[j]] * primes[j]);

        ugly_numbers[i] = next_ugly;

        for (size_t j = 0; j < primes.size(); ++j)
            if (primes[j] * ugly_numbers[pointers[j]] == next_ugly) pointers[j]++;
    }

    return ugly_numbers.back();
}

}
