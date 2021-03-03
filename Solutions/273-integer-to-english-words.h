#pragma once

// 273. Convert a non-negative integer num to its English words representation.

// Solution: (complexity O(N))
// Basic recursive approach where we convert numbers
// by reducing them to smaller subsets. The catch here
// is that you have to know that numbers under 20 all
// have different names and thus you must have a separate
// table for them and other 10s >= 20.

SOLUTION_FOR_PROBLEM(273, "Integer to English Words") {

std::string to_strings(int num)
{
    static const std::string under_20[] = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
        "Eighteen", "Nineteen"
    };

    static const std::string under_100[] = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty",
        "Sixty", "Seventy", "Eighty", "Ninety"
    };

    static const std::string over_1000[] = {
        "Thousand", "Million", "Billion"
    };


    if (num == 0)
        return {};
    if (num < 20)
        return under_20[num];
    if (num < 100) {
        auto str = under_100[num / 10];
        auto remainder = num % 10;

        if (remainder) {
            str += " ";
            str += to_strings(remainder);
        }

        return str;
    } if (num < 1000) {
        auto str = to_strings(num / 100) + " Hundred";
        auto remainder = num % 100;

        if (remainder) {
            str += " ";
            str += to_strings(remainder);
        }

        return str;
    }

    // 1000 -> 1'000'000 -> 1'000'000'000
    // Convert starting from the highest power
    // and then recrusively break down into smaller powers.
    for (int power = 1; power <= 3; ++power) {
        if (num < std::pow(1000, power + 1)) {
            int order = static_cast<int>(std::pow(1000, power));

            auto str = to_strings(num / order) + " " + over_1000[power - 1];
            auto remainder = num % order;

            if (remainder) {
                str += " ";
                str += to_strings(remainder);
            }

            return str;
        }
    }

    return {};
}

std::string numberToWords(int num) {
    auto string = to_strings(num);

    if (string.empty())
        return "Zero";

    return string;
}

SOLVE()
{
    auto res = numberToWords(1234567891);
}

}
