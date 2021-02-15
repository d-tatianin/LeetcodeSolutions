#pragma once

// 961. In a array A of size 2N, there are N+1 unique elements, 
//      and exactly one of these elements is repeated N times.
//      Return the element repeated N times.

// Solution: (complexity O(N))
// Just iterate the array and increment repeat count for each number
// we encounter. If it ever gets to N / 2 we know we found the right number.

SOLUTION_FOR_PROBLEM(961, "N-Repeated Element in Size 2N Array") {

int repeatedNTimes(std::vector<int>& A) {
    std::unordered_map<int, int> number_to_repeat_count;

    for (auto num : A) {
        if (++number_to_repeat_count[num] == A.size() / 2)
            return num;
    }

    return -1;
}

SOLVE()
{
    std::vector<int> vec = { 5, 1, 5, 2, 5, 3, 5, 4 };
    auto res = repeatedNTimes(vec);
}

}
