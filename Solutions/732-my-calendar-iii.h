#pragma once

// 732. Description too long to fit here: https://leetcode.com/problems/my-calendar-iii/

// Solution: (complexity O(N^2))
// We utilize "boundary count".
// Basically, for each range we increment map at it's start by 1,
// and decrement the end by 1. This way, while iterating the map by
// values and adding the values to a variable at any given moment we
// know how many ranges currently have this date booked.

SOLUTION_FOR_PROBLEM(732, "My Calendar III") {

class MyCalendarThree {
public:
    std::map<int, int> map;

    int book(int start, int end) {
        map[start]++;
        map[end]--;

        int max = 0;
        int current = 0;

        for (auto& kv : map) {
            current += kv.second;

            if (current > max)
                max = current;
        }

        return max;
    }
};

SOLVE()
{
    MyCalendarThree myCalendarThree;
    myCalendarThree.book(10, 20); // return 1, The first event can be booked and is disjoint, so the maximum k-booking is a 1-booking.
    myCalendarThree.book(50, 60); // return 1, The second event can be booked and is disjoint, so the maximum k-booking is a 1-booking.
    myCalendarThree.book(10, 40); // return 2, The third event [10, 40) intersects the first event, and the maximum k-booking is a 2-booking.
    myCalendarThree.book(5, 15);  // return 3, The remaining events cause the maximum K-booking to be only a 3-booking.
    myCalendarThree.book(5, 10);  // return 3
    myCalendarThree.book(25, 55); // return 3
}

}
