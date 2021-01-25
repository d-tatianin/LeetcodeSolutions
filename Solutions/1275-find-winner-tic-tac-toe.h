#pragma once

// 1275. Find Winner on a Tic Tac Toe Game

// Solution: (complexity O(N))
// Create 8 int arrays for both players, where
// array[0..2] - row -> number of occupied cells
// array[3..5] - column -> number of occupied cells
// array[6]    - right-to-left diagonal -> number of occupied cells
// array[7]    - left-to-right diagonal -> number of occupied cells
// For every move in array:
// - Increment count for occupied rows for current player.
// - Increment count for occupied columns for current player.
// - Increment count for diagonals, if current cell is a part of one.
// - If any of the incremented diagonals reach 3 the current player wins.
// If we reached the end it's either a draw or the game has not finished yet.
// Thankfully we can easily figure that out by looking at size of the moves array.
// If it's equal to 9 that means all cells are now covered and it's a draw. Pending otherwise.


SOLUTION_FOR_PROBLEM(1275, "Find Winner on a Tic Tac Toe Game") {

std::string tictactoe(const std::vector<std::vector<int>>& moves) {
    int player_one[8] {};
    int player_two[8] {};

    for (size_t i = 0; i < moves.size(); ++i) {
        bool player_one_turn = i % 2 == 0;
        std::string winner_message = player_one_turn ? "A" : "B";

        int* player = player_one_turn ? player_one : player_two;

        auto& coords = moves[i];

        if (++player[coords[0]] == 3)
            return winner_message;
        if (++player[coords[1] + 3] == 3)
            return winner_message;

        if (coords[0] == coords[1] && ++player[6] == 3)
            return winner_message;
        if (coords[0] == 2 - coords[1] && ++player[7] == 3)
            return winner_message;
    }

    return moves.size() == 9 ? "Draw" : "Pending";
}

SOLVE()
{
    auto res = tictactoe({ {0, 0}, { 1, 1 }, { 0, 1 }, { 0, 2 }, { 1, 0 }, { 2, 0 } });
}

}
