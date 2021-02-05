#pragma once

// 137. Given an integer array nums where every element appears three times except for one,
//      which appears exactly once. Find the single element and return it.

// Solution: (complexity O(N))
// The idea here as compared to single number I is that we now
// keep two variables to distinguish between numbers that appeared
// 1 and 3 times, since both are odd it's not as trivial.
// appeared_once only contains the bits that it's allowed to contain by appeared_twice
// and same goes for appeared_twice. Basically if a bit appears once, it gets stored in
// apeared_once, if it appears one more time it gets moved into appeared_twice, if it
// appears one more time while being inside appeared_twice, it gets XORed out of appeared_twice
// and is not contained anywhere after that.

SOLUTION_FOR_PROBLEM(137, "Single Number II") {

int singleNumber(std::vector<int>& nums) {
    int appeared_once = 0;
    int appeared_twice = 0;

    for (auto num : nums) {
        appeared_once  = (appeared_once  ^ num) & ~appeared_twice;
        appeared_twice = (appeared_twice ^ num) & ~appeared_once;
    }

    return appeared_once;
}

SOLVE()
{
    std::vector<int> vec = { 1, 1, 3, 1 };

    auto res = singleNumber(vec);
}

}
