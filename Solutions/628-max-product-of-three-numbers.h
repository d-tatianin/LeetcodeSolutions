#pragma once

// 628. Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

// Solution: (complexity O(N))
// All we have to do is find the 2 lowest and 3 biggest numbers, and see what gives the biggest product.
// The idea behind finding 2 lowest numbers is that in case they're negative, multiplying them together
// would yield a huge positive number, which in turn multiplied by a big positive number yieldes an even
// bigger number

SOLUTION_FOR_PROBLEM(628, "Maximum Product of Three Numbers") {

int maximumProduct(std::vector<int>& nums) {
    int first_smallest = INT_MAX;
    int second_smallest = INT_MAX;

    int first_biggest = INT_MIN;
    int second_biggest = INT_MIN;
    int third_biggest = INT_MIN;

    for (auto num : nums) {
        if (num < first_smallest) {
            second_smallest = first_smallest;
            first_smallest = num;
        } else if (num < second_smallest)
            second_smallest = num;

        if (num > first_biggest) {
            third_biggest = second_biggest;
            second_biggest = first_biggest;
            first_biggest = num;
        } else if (num > second_biggest) {
            third_biggest = second_biggest;
            second_biggest = num;
        } else if (num > third_biggest)
            third_biggest = num;
    }

    return std::max(first_smallest * second_smallest * first_biggest, third_biggest * second_biggest * first_biggest);
}

SOLVE()
{
    std::vector<int> vec = { 1, 2, 3, 4 };
    auto res = maximumProduct(vec);
}

}
