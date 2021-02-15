#pragma once

// 914. In a deck of cards, each card has an integer written on it.
//      Return true iff you can choose X >= 2 such that it is possible to
//      split the entire deck into 1 or more groups of cards, where:
//      - Each group has exactly X cards.
//      - All the cards in each group have the same integer.

//                           vvvvvvv---- complexity of finding a GCD
// Solution: (complexity O(N log^2 N))
// Create a table of card -> occurences.
// Iterate all the cards in the table and find a GCD between
// all of them. If it's greater than 2 we return true.

SOLUTION_FOR_PROBLEM(914, "X of a Kind in a Deck of Cards") {

bool hasGroupsSizeX(std::vector<int>& deck) {
    std::unordered_map<int, int> card_to_count;

    for (auto c : deck)
        auto val = ++card_to_count[c];

    // Euclid's fast GCD algorithm
    auto gcd = [](int l, int r)
    {
        while (l) {
            auto tmp = l;
            l = r % l;
            r = tmp;
        }

        return r;
    };

    int gcd_val = -1;

    for (auto& cc : card_to_count) {
        if (gcd_val == -1)
            gcd_val = cc.second;
        else
            gcd_val = gcd(gcd_val, cc.second);
    }

    return gcd_val >= 2;
}

SOLVE()
{
    std::vector<int> vec = { 1, 2, 3, 4, 4, 3, 2, 1 };
    auto res = hasGroupsSizeX(vec);
}

}
