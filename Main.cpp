// TreeNode struct from leetcode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include "15-3sum.h"
#include "16-3sum-closest.h"
#include "172-factorial-trailing-zeroes.h"
#include "263-ugly-number.h"
#include "264-ugly-number-2.h"
#include "297-serialize-and-deserialize-binary-tree.h"
#include "313-super-ugly-number.h"
#include "371-sum-of-two-integers.h"
#include "509-fibonacci-number.h"
#include "560-subarray-sum-equals-k.h"

void try_297()
{
    problem_297::Codec c;

    TreeNode node(1);
    TreeNode node1(2);
    TreeNode node2(5);
    TreeNode node3(3);

    node.left = &node1;
    node.left->left = &node2;
    node.right = &node3;

    auto serialized = c.serialize(&node);

    auto deserialized = c.deserialize(serialized);
}

int main()
{
    std::vector<int> vec = { 3, -2, -1 };
    auto tsum = problem_15::three_sum(vec);
    auto tsumc = problem_16::three_sum_closest(vec, 5);
    auto zeroes = problem_172::trailing_zeroes(100);
    auto is_ugly = problem_263::is_ugly_number(15);
    auto nth_ugly = problem_264::nth_ugly_number(10);
    try_297();
    auto nth_super_ugly = problem_313::nth_super_ugly_number(12, { 2,7,13,19 });
    auto sum = problem_371::sum(333, 666);
    auto fib = problem_509::fibonacci(10);
    auto count = problem_560::subarray_sum({ 1, 2, 3 }, 1);
}
