#pragma once

// 4. Given two sorted arrays nums1 and nums2 of size m and n
//    respectively, return the median of the two sorted arrays.

// Solution: (complexity O(Log N))
// Run a binary search until we find a point in two arrays
// where both array's rightmost point before middle is less
// than the opposite's array leftmost point after middle
// AND the number of elements on the LHS of middle adds up
// to the exact same number of elements on the RHS of middle.
// A good explaination link: https://www.youtube.com/watch?v=LPFhl65R7ww

SOLUTION_FOR_PROBLEM(4, "Median of Two Sorted Arrays") {

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.empty() && nums2.empty())
        return 0.0;

    size_t n1 = nums1.size();
    auto* arr1 = nums1.data();

    size_t n2 = nums2.size();
    auto* arr2 = nums2.data();

    if (n1 > n2) {
        std::swap(n1, n2);
        std::swap(arr1, arr2);
    }

    int begin = 0;
    int end = static_cast<int>(n1);

    while (begin <= end) {
        auto middle1 = begin + (end - begin) / 2;
        auto middle2 = ((n1 + n2 + 1) / 2) - middle1;

        auto left_max1 = middle1 == 0 ? INT_MIN : arr1[middle1 - 1];
        auto right_min1 = middle1 == n1 ? INT_MAX : arr1[middle1];

        auto left_max2 = middle2 == 0 ? INT_MIN : arr2[middle2 - 1];
        auto right_min2 = middle2 == n2 ? INT_MAX : arr2[middle2];

        if (left_max1 > right_min2)
            end = middle1 - 1;
        else if (left_max2 > right_min1)
            begin = middle1 + 1;
        else {
            auto lmax = std::max(left_max1, left_max2);

            if ((n1 + n2) % 2)
                return lmax;

            return (lmax + std::min(right_min1, right_min2)) / 2.0;
        }
    }

    return 0.0;
}

SOLVE()
{
    std::vector<int> vec1 = { 1, 2 };
    std::vector<int> vec2 = { 3, 4 };

    auto res = findMedianSortedArrays(vec1, vec2);
}

}
