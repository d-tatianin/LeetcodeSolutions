#pragma once

// 238. Given an array nums of n integers where n > 1, return an array output such that
//      output[i] is equal to the product of all the elements of nums except nums[i].

// Solution: (complexity O(N))
// We do two passes:
// - In first pass we make answer[i] equal to the product of answer[i - 1] by num[i - 1].
//   This way we get an array, where element at i is product of all elements before itself.
// - In the second pass we want to make the answer array elements contain the product before itself
//   multiplied by the product after itself. The way we do this is we create a product_on_the_right
//   variable and start iterating from right to left. At first the product on the right is equal to 1,
//   so the last element in the answer array stays as is (since it's already correct). Then product on
//   the right gets multiplied by the original number at that index. This way, multiplying answer[i] * product_on_the_right
//   we get the product of all numbers with nums[i] excluded from that product. It's then included afterwards when
//   we multiply product_on_the_right by the original value at nums[i].

SOLUTION_FOR_PROBLEM(238, "Product of Array Except Self") {

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> answer(nums.size());
    answer[0] = 1;

    for (size_t i = 1; i < nums.size(); ++i)
        answer[i] = answer[i - 1] * nums[i - 1];

    int product_on_the_right = 1;

    for (size_t i = nums.size(); i-- > 0;) {
        answer[i] = answer[i] * product_on_the_right;
        product_on_the_right *= nums[i];
    }

    return answer;
}

SOLVE()
{
    std::vector<int> vec = { 1, 2, 3, 4 };
    auto res = productExceptSelf(vec);
}

}
