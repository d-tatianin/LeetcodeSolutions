#pragma once

// 252. Given an array of meeting time intervals consisting of start and end times,
//      determine if a person could attend all meetings.

// Solution: (complexity O(N Log N))
// Sort ranges by start, check if the end of range overlaps the beginning of next range,
// if it does, the person cannot attend all meetings.

SOLUTION_FOR_PROBLEM(252, "Meeting Rooms") {

bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty())
        return true;

    std::sort(intervals.begin(), intervals.end(),
        [](auto& l, auto& r)
        {
            return l[0] < r[0];
        });

    for (size_t i = 0; i < intervals.size() - 1; ++i)
    {
        if (intervals[i][1] > intervals[i + 1][0])
            return false;
    }

    return true;
}

SOLVE()
{
    std::vector<std::vector<int>> vec = { { 0, 1}, {1, 2}, {1, 3} };
    auto res = canAttendMeetings(vec);
}

}
