#include <initializer_list>
#include <ctime>

// TreeNode struct from leetcode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ListNode struct from leetcode
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* make_list(std::initializer_list<int> numbers)
{

    ListNode* head = nullptr;
    ListNode* curr = nullptr;

    for (auto n : numbers) {
        if (!head) {
            head = new ListNode(n);
            curr = head;
            continue;
        }

        curr->next = new ListNode(n);
        curr = curr->next;
    }

    return head;
}

#include "3-longest-substring-without-repeating.h"
#include "15-3sum.h"
#include "16-3sum-closest.h"
#include "56-merge-intervals.h"
#include "66-plus-one.h"
#include "116-populating-next-right.h"
#include "172-factorial-trailing-zeroes.h"
#include "263-ugly-number.h"
#include "264-ugly-number-2.h"
#include "278-first-bad-version.h"
#include "297-serialize-and-deserialize-binary-tree.h"
#include "313-super-ugly-number.h"
#include "371-sum-of-two-integers.h"
#include "382-linked-list-random-node.h"
#include "509-fibonacci-number.h"
#include "560-subarray-sum-equals-k.h"
#include "709-to-lower-case.h"
#include "762-partition-labels.h"
#include "819-most-common-word.h"
#include "833-find-and-replace-in-string.h"
#include "836-rectangle-overlap.h"
#include "905-sory-array-by-parity.h"
#include "941-valid-mountain-array.h"
#include "1010-pair-of-songs-divisible-by-60.h"
#include "1146-snapshot-array.h"
#include "1275-find-winner-tic-tac-toe.h"
#include "1344-angle-between-hands-of-clock.h"
#include "1352-product-of-the-last-k-numbers.h"
#include "1544-make-the-string-great.h"

void try_116()
{
    using Node = problem_116::Node;

    Node n  { 1 };
    Node n1 { 2 };
    Node n2 { 3 };

    n.left = &n1;
    n.right = &n2;

    problem_116::connect(&n);
}

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

void try_382()
{
    auto list = make_list({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });

    problem_382::Solution s(list);
    srand(time(nullptr));

    auto r = s.get_random();
    r = s.get_random();
    r = s.get_random();
    r = s.get_random();
    r = s.get_random();
    r = s.get_random();
    r = s.get_random();
    r = s.get_random();
}

void try_833()
{
    std::string S = "abcd";
    std::vector<int> indexes = { 0, 2 };
    std::vector<std::string> sources = { "a", "cd" };
    std::vector<std::string> targets = { "eee", "ffff" };

    auto res = problem_833::find_replace_string(S, indexes, sources, targets);
}

void try_1146()
{
    problem_1146::SnapshotArray array(3);
    array.set(0, 0);
    array.snap();
    array.set(0, 1);
    auto res = array.get(0, 0);
}

void try_1352()
{
    problem_1352::ProductOfNumbers pr;

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

int main()
{
    auto len = problem_3::length_of_longest_substring("abcabcbb");
    std::vector<int> vec = { 3, -2, -1 };
    auto tsum = problem_15::three_sum(vec);
    auto tsumc = problem_16::three_sum_closest(vec, 5);

    std::vector<std::vector<int>> vec1 = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
    auto merged = problem_56::merge(vec1);

    std::vector<int> vec2 = { 9, 9, 9 };
    auto arr = problem_66::plus_one(vec2);
    try_116();
    auto zeroes = problem_172::trailing_zeroes(100);
    auto is_ugly = problem_263::is_ugly_number(15);
    auto nth_ugly = problem_264::nth_ugly_number(10);
    auto bad_version = problem_278::first_bad_version(10);
    try_297();
    auto nth_super_ugly = problem_313::nth_super_ugly_number(12, { 2,7,13,19 });
    auto sum = problem_371::sum(333, 666);
    try_382();
    auto fib = problem_509::fibonacci(10);
    auto count = problem_560::subarray_sum({ 1, 2, 3 }, 1);
    auto lower = problem_709::to_lower("HELLO World");
    auto word = problem_819::most_common_word("hello hello word", { "hello" });
    try_833();
    auto ovrl = problem_836::rects_overlap({ 0,0,2,2 }, { 1,1,3,3 });
    vec = problem_905::sort_array_by_parity(vec);
    auto isval = problem_941::valid_mountain_array({ 0,3,2,1 });
    auto vals = problem_1010::pair_count_divisible_by_60({ 30,20,150,100,40 });
    try_1146();
    auto res = problem_1275::play_tictactoe({ {0, 0}, { 1, 1 }, { 0, 1 }, { 0, 2 }, { 1, 0 }, { 2, 0 } });
    auto deg = problem_1344::angle_between_clock_hands(12, 30);
    try_1352();
    auto str = problem_1544::make_string_good("leEeetcode");
}
