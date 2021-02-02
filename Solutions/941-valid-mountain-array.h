#pragma once

// 941. Given an array of integers arr, return true if and only if it is a valid mountain array.

// Solution: (complexity O(N))
// Walk up until we meet a number that's not greater than the previous.
// If we stopped at index 1 (aka haven't moved) or at index == size (aka moved to the end) return false, as it's invalid.
// Walk down until we meet a number that's not less than the previous.
// If we ended up at index == size it's a valid mountaint array, otherwise we encounter an invalid number.

SOLUTION_FOR_PROBLEM(941, "Valid Mountain Array")  {

bool validMountainArray(const std::vector<int>& arr) {
    if (arr.size() < 3)
        return false;

    size_t index = 1;

    while (index < arr.size() && arr[index - 1] < arr[index])
        ++index;

    if (index == 1 || index == arr.size())
        return false;

    while (index < arr.size() && arr[index - 1] > arr[index])
        ++index;

    return index == arr.size();
}

SOLVE()
{
    auto res = validMountainArray({ 0,3,2,1 });
}

}
