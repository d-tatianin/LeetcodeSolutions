#pragma once

// 1156. Given a string text, we are allowed to swap two of the characters in the string.
//       Find the length of the longest substring with repeated characters.

// Solution: (complexity O(N))
// First we compute an array of ranges for each character, in form: character -> { (begin, end), ... }
// Then we iterate the computed ranges for each character, and record the length of current range as max answer
// in case it's bigger. We can also increment it by 1 if it's not the only range of this character, since then we
// can steal a character from a different range and append it at the end of our range. There's also an even better case
// that we're looking for. That being the case where range at i - 1 is exactly one character behind the beginning of
// the current range. This means we can merge the two ranges and record their added up length as best answer.
// We can also increment the length by 1 for the same reason above.

SOLUTION_FOR_PROBLEM(1156, "ProblemName") {

int maxRepOpt1(std::string text) {
    if (text.size() < 2)
        return static_cast<int>(text.size());

    struct range {
        size_t begin;
        size_t end;
    };

    std::vector<range> map[26];

    for (size_t i = 0; i < text.size(); ++i) {
        auto& range = map[text[i] - 'a'].emplace_back();
        range.begin = i;
        range.end = i;

        while (++range.end && (i < text.size() - 1 && text[i] == text[i + 1]))
            i++;
    }

    size_t max_answer = 0;

    for (auto& char_ranges : map) {
        if (char_ranges.empty())
            continue;

        for (size_t i = 0; i < char_ranges.size(); ++i) {
            auto& range = char_ranges[i];

            size_t length = range.end - range.begin;
            if (char_ranges.size() > 1)
                length += 1;

            max_answer = std::max(max_answer, length);

            if (i == 0)
                continue;

            auto& previous_range = char_ranges[i - 1];

            // previous range is not one char behind the current, so we cannot merge
            if (previous_range.end + 1 != range.begin)
                continue;

            auto combined_length = (range.end - range.begin) + (previous_range.end - previous_range.begin);

            // Since there's an extra range available, we can steal a char from it thus incrementing our range by 1
            if (char_ranges.size() > 2)
                combined_length += 1;

            max_answer = std::max(max_answer, combined_length);
        }
    }

    return static_cast<int>(max_answer);
}

SOLVE()
{
    auto res = maxRepOpt1("aaabaaaca");
}

}
