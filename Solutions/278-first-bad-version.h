#pragma once

// 278. You are a product manager and currently leading a team to develop a new product.
//      Unfortunately, the latest version of your product fails the quality check.
//      Since each version is developed based on the previous version, all the versions after a bad version are also bad.
//      Suppose you have n versions[1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
//      You are given an API bool isBadVersion(version) which returns whether version is bad.
//      Implement a function to find the first bad version.You should minimize the number of calls to the API.

// Solution: (complexity O(log N))
// Just a slightly modified version of binary search, nothing more.

PROBLEM(278, "First Bad Version") {

inline bool isBadVersion(int n) { return n > 3; }

inline int firstBadVersion(int n) {
    auto left = 1;
    auto right = n;

    while (left <= right) {
        auto middle = left + (right - left) / 2;

        if (isBadVersion(middle))
            right = middle - 1;
        else
            left = middle + 1;
    }

    return left;
}

TRY_SOLVE()
{
    auto res = firstBadVersion(99);
}

}
