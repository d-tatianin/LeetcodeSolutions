#pragma once

// 212. Given an m x n board of characters and a list of strings words, return all words on the board.

// Solution 1: (complexity O(n * m * 4^L))
// Solution 1 is based on the solution #79. The only difference is we use a set to check
// what words we have already seen to prevent looking for them twice.
// --------------------------------------------------------------------------------------
// Solution 2: (complexity O(?))
// More of what this problem is actually about, you are supposed to implement a trie
// and use it to effectively scan for words by removing already seen.

SOLUTION_FOR_PROBLEM(212, "ProblemName") {

// ---------------------------- SOLUTION 1

bool do_check(int x, int y, std::vector<std::vector<char>>&board, const std::string & word, size_t index)
{
    if (index == word.size())
        return true;
    if (x < 0 || x > board[0].size() - 1)
        return false;
    if (y < 0 || y > board.size() - 1)
        return false;
    if (board[y][x] == '\0')
        return false;
    if (word[index] != board[y][x])
        return false;

    char temp = board[y][x];
    board[y][x] = '\0';

    bool res = do_check(x - 1, y, board, word, index + 1) ||
               do_check(x + 1, y, board, word, index + 1) ||
               do_check(x, y + 1, board, word, index + 1) ||
               do_check(x, y - 1, board, word, index + 1);

    board[y][x] = temp;

    return res;
}

std::vector<std::string> findWords1(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
    std::set<std::string> seen;

    for (size_t y = 0; y < board.size(); ++y) {
        for (size_t x = 0; x < board[0].size(); ++x) {
            for (auto& word : words) {
                if (seen.count(word))
                    continue;
                if (board[y][x] == word[0]) {
                    if (do_check(static_cast<int>(x), static_cast<int>(y), board, word, 0))
                        seen.emplace(word);
                }
            }
        }
    }

    std::vector<std::string> ans;
    ans.reserve(seen.size());

    for (auto& word : seen)
        ans.emplace_back(std::move(word));

    return ans;
}

// ---------------------------- SOLUTION 2

struct Trie {
    std::string word;
    Trie* next[26];
    int subtrees = 0;
};

Trie* generate_trie(std::vector<std::string>& words) {
    Trie* root = new Trie();

    for (auto& word : words) {
        auto current = root;

        for (char c : word) {
            current->subtrees++;
            if (!current->next[c - 'a'])
                current->next[c - 'a'] = new Trie();
            current = current->next[c - 'a'];
        }

        current->word = std::move(word);
    }

    return root;
}

void do_check2(int x, int y, std::vector<std::vector<char>>& board, Trie* trie, std::vector<std::string>& answer)
{
    if (x < 0 || x > board[0].size() - 1)
        return;
    if (y < 0 || y > board.size() - 1)
        return;
    if (board[y][x] == '\0')
        return;

    auto* this_node = trie->next[board[y][x] - 'a'];
    if (!this_node)
        return;

    if (!this_node->word.empty()) {
        answer.emplace_back(std::move(this_node->word));
        this_node->word.clear();

        if (this_node->subtrees == 0) {
            Trie* to_delete = nullptr;
            std::swap(trie->next[board[y][x] - 'a'], to_delete);
            trie->subtrees--;
            delete to_delete;
            return;
        }
    }

    char temp = board[y][x];
    board[y][x] = '\0';

    do_check2(x - 1, y, board, this_node, answer);
    do_check2(x + 1, y, board, this_node, answer);
    do_check2(x, y + 1, board, this_node, answer);
    do_check2(x, y - 1, board, this_node, answer);

    board[y][x] = temp;
}

std::vector<std::string> findWords2(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
    std::vector<std::string> answer;

    auto* trie = generate_trie(words);

    for (size_t y = 0; y < board.size(); ++y) {
        for (size_t x = 0; x < board[0].size(); ++x) {
            if (trie->next[board[y][x] - 'a'])
                do_check2(x, y, board, trie, answer);
        }
    }

    return answer;
}

SOLVE()
{
    std::vector<std::vector<char>> board = {
         { 'o', 'a', 'a', 'n' },
         { 'e', 't', 'a', 'e' },
         { 'i', 'h', 'k', 'r' },
         { 'i', 'f', 'l', 'v' }
    };

    std::vector<std::string> words = { "oath", "pea", "eat", "rain" };

    auto res = findWords1(board, words);
    auto res1 = findWords2(board, words);
;}

}
