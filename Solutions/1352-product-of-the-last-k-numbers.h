#pragma once

// 1352. Implement the class ProductOfNumbers that supports two methods:
//       1. add(int num) -  Adds the number num to the back of the current list of numbers.
//       2. getProduct(int k) - Returns the product of the last k numbers in the current list.


// Solution: (complexity O(1))
// We solve this problem by keeping a product of all previous prefixes in the current.
// Whenever we encounter 0 in add() we reset the array with { 1 } to simplify cases where k == size - 1.
// If we're asked to retrieve a product of k >= size, we know for sure the product at k was zero before we reset the array,
// so we can just return 0.

PROBLEM(1352, "Product of the Last K Numbers") {

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

TRY_SOLVE()
{
    ProductOfNumbers pr;

    // Example from leetcode
    pr.add(3);        // [3]
    pr.add(0);        // [3,0]
    pr.add(2);        // [3,0,2]
    pr.add(5);        // [3,0,2,5]
    pr.add(4);        // [3,0,2,5,4]
    pr.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
    pr.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
    pr.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
    pr.add(8);        // [3,0,2,5,4,8]
    pr.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32 
}

}
