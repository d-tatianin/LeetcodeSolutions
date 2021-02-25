#pragma once

// 204. Count the number of prime numbers less than a non-negative number, n.

// Solution: (complexity O(n log log n)))
// We just follow this algorithm: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

SOLUTION_FOR_PROBLEM(204, "Count Primes") {

int countPrimes(int n) {
    if (n < 2)
        return 0;

    std::vector<bool> array(n, true);
    array[0] = array[1] = false;

    for (int number = 2; number <= sqrt(n); ++number) {
        if (!array[number])
            continue;

        int number2 = number << 1;

        while (number2 < n) {
            array[number2] = false;
            number2 += number;
        }
    }

    int count = 0;
    for (auto val : array)
        count += val;

    return count;
}

SOLVE()
{
    auto res = countPrimes(10);
}

}
