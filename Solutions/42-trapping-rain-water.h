#pragma once

// 42. Given n non-negative integers representing an elevation map where
//     the width of each bar is 1, compute how much water it can trap after raining.

// Solution 1: (time complexity O(N), space O(N))
// Compute max from left to right, compute max from right to left.
// For each index pick the minimum between two maximums and subtract
// the ith height from that minimum. Finally add the remaining height
// to answer.
//--------------------------------------------------------------------
// Solution 2: (time complexity O(N), space O(1))
// Two pointer approach where we iterate the lhs as long as
// its smaller than rhs, and wise versa while adding
// the difference between max height and current pointer height
// if it's smaller or recording it if it's bigger. The key idea
// here is that we must realize that as long as there's a bigger
// tower on one side we can afford to scan the opposite side while
// it's smaller because we're bounded by only that side's height.

SOLUTION_FOR_PROBLEM(42, "Trapping Rain Water") {

int trapSlow(std::vector<int>& height) {
    if (height.empty())
        return 0;

    std::vector<int> l_to_r(height.size());
    std::vector<int> r_to_l(height.size());

    l_to_r[0] = height[0];
    for (size_t i = 1; i < height.size(); ++i)
        l_to_r[i] = std::max(l_to_r[i - 1], height[i]);

    r_to_l[height.size() - 1] = height.back();
    for (size_t i = height.size() - 1; i-- > 0;)
        r_to_l[i] = std::max(r_to_l[i + 1], height[i]);

    int answer = 0;

    for (size_t i = 0; i < height.size(); ++i) {
        int min_height = std::min(l_to_r[i], r_to_l[i]);
        answer += min_height - height[i];
    }

    return answer;
}

int trap(std::vector<int>& height) {
    if (height.empty())
        return 0;

    int answer = 0;

    int left = 0;
    int right = static_cast<int>(height.size() - 1);

    int left_max = 0;
    int right_max = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] > left_max)
                left_max = height[left];
            else
                answer += left_max - height[left];

            ++left;
        } else {
            if (height[right] > right_max)
                right_max = height[right];
            else
                answer += right_max - height[right];

            --right;
        }
    }

    return answer;
}

SOLVE()
{
    std::vector<int> vec = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

    auto res = trapSlow(vec);
    auto res1 = trap(vec);

}

}
