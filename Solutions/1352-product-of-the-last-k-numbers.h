#pragma once

// 1352. Implement the class ProductOfNumbers that supports two methods:
//       1. add(int num) -  Adds the number num to the back of the current list of numbers.
//       2. getProduct(int k) - Returns the product of the last k numbers in the current list.


// Solution: (complexity O(1))
// We solve this problem by keeping a product of all previous prefixes in the current.
// Whenever we encounter 0 in add() we reset the array with { 1 } to simplify cases where k == size - 1.
// If we're asked to retrieve a product of k >= size, we know for sure the product at k was zero before we reset the array,
// so we can just return 0.

namespace problem_1352 {

class ProductOfNumbers {
public:
    ProductOfNumbers()
        : products { 1 }
    {
    }

    void add(int num) {
        if (num)
            products.push_back(products.back() * num);
        else
            products = { 1 };
    }

    int getProduct(int k) {
        if (k >= products.size())
            return 0;

        return products.back() / products[products.size() - k - 1];
    }

private:
    std::vector<int> products;
};

}
