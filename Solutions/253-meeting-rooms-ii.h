#pragma once

// 253. Given an array of meeting time intervals consisting of start and end times,
//      find the minimum number of conference rooms required.

// Solution: (complexity O(N Log N))
// 1. Sort intervals in ascending order.
// 2. Use a heap to find the number of overlapping intervals.
//    If heap's top interval's end is less than the new interval's begin,
//    we can afford to remove it from the heap and push the new one in since
//    there is no overlap between them, thus we only need 1 room for both.
// 3. Number of items that remains in heap is the number of rooms required.

SOLUTION_FOR_PROBLEM(253, "Meeting Rooms II") {

int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty())
        return 0;

    std::sort(intervals.begin(), intervals.end(),
        [](auto& l, auto& r)
        {
            if (l[0] == r[0])
                return l[1] < r[1];

            return l[0] < r[0];
        });


    std::priority_queue<int> rooms;

    for (auto& interval : intervals) {
        if (!rooms.empty() && rooms.top() <= interval[0])
            rooms.pop();

        rooms.push(interval[1]);
    }


    return static_cast<int>(rooms.size());
}

SOLVE()
{
    std::vector<std::vector<int>> vec = { { 0, 1}, {1, 2}, {1, 3} };
    auto res = minMeetingRooms(vec);
}

}
