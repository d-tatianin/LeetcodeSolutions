#pragma once

// 9. Given an integer x, return true if x is palindrome integer.

// Solution: (complexity O(Log N))
// If x is less than zero or last digit of x is 0 when x itself is not zero,
// it's not a palindrome. After we're done with those cases, we reverse half
// of x while dividing it to become the upper half, and in the end check if reversed
// lower half is equal to the above half, or (in case if it's an odd length palindrome),
// we check that equality with reversed rhs divided by 10 to skip that middle part.

SOLUTION_FOR_PROBLEM(9, "Palindrome Number") {

bool isPalindrome(int x) {
    if (x < 0 || (x > 0 && (x % 10 == 0)))
        return false;

    int rhs = 0;

    while (x > rhs) {
        rhs *= 10;
        rhs += x % 10;
        x /= 10;
    }

    return rhs == x || rhs / 10 == x;
}

SOLVE()
{
    auto res = isPalindrome(121);
}

}
