// TreeNode struct from leetcode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include "172-factorial-trailing-zeroes.h"
#include "297-serialize-and-deserialize-binary-tree.h"
#include "371-sum-of-two-integers.h"

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
    auto zeroes = problem_172::trailing_zeroes(100);
    try_297();
    auto sum = problem_371::sum(333, 666);
}
