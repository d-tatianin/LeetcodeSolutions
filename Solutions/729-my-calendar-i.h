#pragma once

// 729. Description too long to fit here: https://leetcode.com/problems/my-calendar-i/

// Solution: (complexity O(Log N))
// Keep all ranges sorted in a binary tree.
// When book is called check the potential ranges
// before and after it and see if they overlap
// the new range.

SOLUTION_FOR_PROBLEM(729, "My Calendar I") {

class MyCalendar {
public:
    bool book(int start, int end) {
        if (ranges.empty()) {
            ranges[start] = end;
            return true;
        }

        auto itr = ranges.lower_bound(start);
        auto itr_after = itr;

        // Check for direct hit
        if (itr != ranges.end() && itr->first == start)
            return false;

        // Check range before if it exists
        if (itr != ranges.begin()) {
            --itr;

            if (itr->second > start)
                return false;
        }

        // Check range after if it exists
        if (itr_after != ranges.end() && end > itr_after->first)
            return false;

        ranges[start] = end;
        return true;
    }

private:
    std::map<int, int> ranges;
};

SOLVE()
{
    auto cal = MyCalendar();
    cal.book(10, 20); // returns true
    cal.book(15, 25); // returns false
    cal.book(20, 30); // returns true
}

}
