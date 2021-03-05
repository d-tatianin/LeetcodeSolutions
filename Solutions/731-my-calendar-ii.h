#pragma once

// 731. Description too long to fit here: https://leetcode.com/problems/my-calendar-ii/

// Solution 1: (complexity O(N))
// Same idea as calendar-iii.
// ------------------------------
// Solution 2: (complexity O(Log N))
// Same idea as calendar-i but 2 sets instead of 1.

SOLUTION_FOR_PROBLEM(731, "My Calendar II") {

class MyCalendarTwo {
public:
    std::map<int, int> map;

    bool book1(int start, int end) {
        map[start]++;
        map[end]--;

        int sum = 0;
        for (auto& kv : map) {
            sum += kv.second;

            if (sum >= 3) {
                map[start]--;
                map[end]++;
                return false;
            }
        }

        return true;
    }

    struct range {
        int begin;
        int end;

        friend bool operator<(range l, range r)
        {
            return l.end <= r.begin;
        }
    };

    std::set<range> single_booked;
    std::set<range> double_booked;

    bool book2(int begin, int end) {
        auto [single_begin, single_end] = single_booked.equal_range({ begin, end });

        if (single_begin == single_end) {
            single_booked.insert({ begin, end });
            return true;
        }

        auto [double_begin, double_end] = double_booked.equal_range({ begin, end });
        if (double_begin != double_end)
            return false;

        for (auto it = single_begin; it != single_end; ++it)
            double_booked.insert({ std::max(begin, it->begin), std::min(end, it->end) });

        range new_range = { std::min(single_begin->begin, begin), std::max(std::prev(single_end)->end, end) };
        single_booked.erase(single_begin, single_end);
        single_booked.insert(new_range);

        return true;
    }
};

SOLVE()
{
    MyCalendarTwo cal;

    cal.book1(10, 20); // returns true
    cal.book1(50, 60); // returns true
    cal.book1(10, 40); // returns true
    cal.book1(5, 15); // returns false
    cal.book1(5, 10); // returns true
    cal.book1(25, 55); // returns true

    cal.book2(10, 20); // returns true
    cal.book2(50, 60); // returns true
    cal.book2(10, 40); // returns true
    cal.book2(5, 15); // returns false
    cal.book2(5, 10); // returns true
    cal.book2(25, 55); // returns true
}

}
