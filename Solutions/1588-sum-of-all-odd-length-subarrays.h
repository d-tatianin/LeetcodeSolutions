#pragma once

#include <vector>

// 1588. Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.

// Solution: (complexity O(N))
// We can easily count the number of occurences of the current index in all subarrays:
// for array [1, 2, 3, 4], the occurences of 3 is:
// index 0:   |________| -> 3 occurs 2 times in subarrays [1 ... 4], [1 ... 3]
// index 1:      |_____| -> 3 occurs 2 times in subarrays [2 ... 4], [2 ... 3]
// index 2:         |__| -> 3 occurs 2 times in subarrays [3 ... 4], [3]
// ----------------------------------------------------------------------------
// So looking at the above example we can see that the formula to calculate occurences of i is: (N - i) * i + (N - i) or simplified (N - i) * (i + 1).
// Now to calculate occrences in odd subarrays all we have to do is perform a ceilied division by 2 on total occurences or simply: (occurence + 1) / 2.
// So to find the total sum we do the thing above for every element in the array, which yields O(N) complexity.

SOLUTION_FOR_PROBLEM(1588, "Sum of All Odd Length Subarrays") {

int sumOddLengthSubarrays(std::vector<int>& arr) {
    int sum = 0;

    for (size_t i = 0; i < arr.size(); ++i) {
        size_t occurences_of_this_element = (arr.size() - i) * (i + 1);

        sum += static_cast<int>(arr[i] * ((occurences_of_this_element + 1) / 2));
    }

    return sum;
}


SOLVE()
{
    std::vector<int> vec = { 1, 4, 2, 5, 3 };

    auto res = sumOddLengthSubarrays(vec);
}

}
