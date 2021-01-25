#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// 819. Write a program to check whether a given number is an ugly number.

// Solution: (complexity O(N + M))
// In order to optimize banned word search we put all of them in a hash set. This costs us O(M)
// for each character in the paragraph:
// - if its a letter, append it to the current word
// - otherwise, if the current word is not empty, add it into the word map and increment frequency
// - if current word frequency is greater than current best, record it as best and save a pointer to current word

SOLUTION_FOR_PROBLEM(819, "Most Common Word") {

std::string mostCommonWord(const std::string& paragraph, const std::vector<std::string>& banned) {
    std::unordered_map<std::string, size_t> words_to_frequency;

    std::unordered_set<std::string> banned_words;
    for (auto& banned_word : banned)
        banned_words.emplace(banned_word);

    std::string current_word;
    size_t best_frequency = 0;
    const std::string* best_word = nullptr;

    for (size_t i = 0; i < paragraph.size(); ++i) {
        char c = paragraph[i];

        if (isalpha(c)) {
            current_word += tolower(c);

            if (i != paragraph.size() - 1)
                continue;
        }

        if (!current_word.empty()) {
            if (banned_words.count(current_word)) {
                current_word.clear();
                continue;
            }

            std::unordered_map<std::string, size_t>::iterator this_pair = words_to_frequency.find(current_word);

            if (this_pair == words_to_frequency.end())
                this_pair = words_to_frequency.emplace(std::make_pair(std::move(current_word), 1)).first;
            else
                ++this_pair->second;

            if (this_pair->second > best_frequency) {
                best_frequency = this_pair->second;
                best_word = &this_pair->first;
            }

            current_word.clear();
        }
    }

    return best_word ? *best_word : "";
}

SOLVE()
{
    auto res = mostCommonWord("hello hello word", { "hello" });
}

}
