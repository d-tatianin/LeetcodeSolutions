#pragma once

#include <vector>

// 836. An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinate of its bottom-left corner,
//      and (x2, y2) is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis,
//      and its left and right edges are parallel to the Y-axis. Two rectangles overlap if the area of their intersection is positive.
//      To be clear, two rectangles that only touch at the corner or edges do not overlap.
//      Given two axis - aligned rectangles rec1 and rec2, return true if they overlap, otherwise return false.

// Solution: (complexity O(1))
// All we have to do is to check that the maximum x1 is smaller than the smallest x2,
// and that the maximum y1 is smaller than the smallest y2

namespace problem_836 {

inline bool rects_overlap(const std::vector<int>& rec1, const std::vector<int>& rec2) {
    return std::max(rec1[0], rec2[0]) < std::min(rec1[2], rec2[2]) &&
           std::max(rec1[1], rec2[1]) < std::min(rec1[3], rec2[3]);
}

}
