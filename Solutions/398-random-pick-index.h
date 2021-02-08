#pragma once

// 398. Given an array of integers with possible duplicates, randomly output the index of a given target number.
//      You can assume that the given target number must exist in the array.

// Solution: (complexity O(N))
// We generate a map from number to indices at which it was present in the array.
// Then all we have to do in pick() is pick a random number from 0 to number of occurences of target.

SOLUTION_FOR_PROBLEM(398, "Random Pick Index") {

class Solution {
public:
    Solution(std::vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
            num_to_indices[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        auto& indices = num_to_indices[target];

        return static_cast<int>(indices[rand() % indices.size()]);
    }

private:
    std::unordered_map<int, std::vector<size_t>> num_to_indices;
};

SOLVE()
{
    std::vector<int> vec = { 1, 2, 3, 3, 3 };

    Solution solution(vec);
    solution.pick(3);
}

}
