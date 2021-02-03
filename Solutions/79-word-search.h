#pragma once

// 79. Given an m x n board and a word, find if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells,
// where "adjacent" cells are horizontally or vertically neighboring.
// The same letter cell may not be used more than once.

// Solution: (complexity O(n * m * 4^L) L being the longest word length)
// For each character from left to right, top to bottom:
// if it matches the beginning of the word, begin checking the current character with index 0:
// The check function works as follows:
// If current index to check is past the end of word, return true, we found a match (base case).
// If current character doesn't match word[i], break the recursion and return false.
// Otherwise continue the recursion further by checking the other characters next to current:
// Mark the current x,y index as visited so we don't count the character twice.
// Check the left of the current character for the next match with index i + 1.
// Check the right of the current character for the next match with index i + 1.
// Check the top of the current character for the next match with index i + 1.
// Check the bottom of the current character for the next match with index i + 1.
// Unmark as visited so that next time this index gets checked it can be counted.

SOLUTION_FOR_PROBLEM(79, "Word Search") {

bool check_next(int x, int y, std::vector<std::vector<char>>& board, size_t i, const std::string& word)
{
    if (i == word.size())
        return true;

    if (x < 0 || x >= board[0].size())
        return false;
    if (y < 0 || y >= board.size())
        return false;
    if (board[y][x] == '\0')
        return false;
    if (word[i] != board[y][x])
        return false;

    char temp = board[y][x];
    board[y][x] = '\0';

    auto did_find = check_next(x - 1, y, board, i + 1, word) ||
                    check_next(x + 1, y, board, i + 1, word) ||
                    check_next(x, y - 1, board, i + 1, word) ||
                    check_next(x, y + 1, board, i + 1, word);

    board[y][x] = temp;

    return did_find;
}

bool exist(std::vector<std::vector<char>>& board, std::string word) {
    for (int y = 0; y < static_cast<int>(board.size()); ++y) {
        for (int x = 0; x < static_cast<int>(board[0].size()); ++x) {
            if (board[y][x] != word[0])
                continue;

            if (check_next(x, y, board, 0, word))
                return true;
        }
    }

    return false;
}

SOLVE()
{
    std::vector<std::vector<char>> vec = { { 'A', 'B', 'C', 'E' },
                                           { 'S', 'F', 'C', 'S' },
                                           { 'A', 'D', 'E', 'E' } };

    auto res = exist(vec, "ABCCED");
}

}
