#pragma once

// 1769. Too long to fit here: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

// Solution: (complexity O(N))
// We use two arrays (left_to_right, right_to_left)
// where we accumulate the total number of moves required
// for each position at i to move all boxes either from left
// or from right depending on the array.
// Then the total sum for each index is lhs[i] + rhs[i]
// Note that this can be optimized to use less passes but the
// complexity will still be O(N).

SOLUTION_FOR_PROBLEM(1769, "Minimum Number of Operations to Move All Balls to Each Box") {

std::vector<int> minOperations(std::string boxes) {
    std::vector<int> left_to_right(boxes.size());
    int left_to_right_boxes = 0;

    std::vector<int> right_to_left(boxes.size());
    int right_to_left_boxes = 0;

    for (size_t i = 1; i < boxes.size(); ++i)
    {
        if (left_to_right[i - 1])
            left_to_right[i] = left_to_right[i - 1] + left_to_right_boxes;

        left_to_right[i] += boxes[i - 1] == '1';

        if (boxes[i - 1] == '1')
            left_to_right_boxes++;
    }

    for (size_t i = boxes.size() - 1; i-- > 0;)
    {
        if (right_to_left[i + 1])
            right_to_left[i] = right_to_left[i + 1] + right_to_left_boxes;

        right_to_left[i] += boxes[i + 1] == '1';

        if (boxes[i + 1] == '1')
            right_to_left_boxes++;
    }

    std::vector<int> out(boxes.size());

    for (size_t i = 0; i < out.size(); ++i) {
        out[i] = left_to_right[i] + right_to_left[i];
    }

    return out;
}

SOLVE()
{
    auto res = minOperations("110");
}

}
