#pragma once

// 1089. Given a fixed length array arr of integers, duplicate each occurrence of zero,
//       shifting the remaining elements to the right.
//       Note that elements beyond the length of the original array are not written.
//       Do the above modifications to the input array in place, do not return anything from your function.

// Solution: (complexity O(N))
// Count the number of zeroes in the array.
// Start going backwards from last index (we call it 'i') until we hit the beginning:
// - Decrement the duplicated array index.
// - If duplicated array index is inside the main array, set the value at that index to current value of i.
// - If we ended up setting the value to 0, we have to also set one more value to 0, as it's duplicated.

// 1 0 2 3 <- contains 1 zero, so the duplicated length is 5
// 1 0 2 3 _
//       ^ ^- duplicated pointer (idx 5)
//       |
//       |- i pointer (idx 3)

// 1 0 2 3 (3) (i = 3, dup = 4) since arr[4] is out of bounds, 3 is discarded
// 1 0 2 2 (i = 2, dup = 3)
// 1 0 0 2 (i = 1, dup = 2)
// 1 0 0 2 (i = 1, dup = 1)
// 1 0 0 2 (i = 0, dup = 0)

SOLUTION_FOR_PROBLEM(1089, "Duplicate Zeros") {

void duplicateZeros(std::vector<int>& arr) {
    if (arr.empty())
        return;

    size_t duplicated_length = std::count(arr.begin(), arr.end(), 0) + arr.size();

    for (size_t i = arr.size(); i-- > 0;) {
        if (--duplicated_length < arr.size())
            arr[duplicated_length] = arr[i];
        if (arr[i] == 0 && --duplicated_length < arr.size())
            arr[duplicated_length] = 0;
    }
}

SOLVE()
{
    std::vector<int> vec = { 1, 0, 2 };
    duplicateZeros(vec);
}

}
