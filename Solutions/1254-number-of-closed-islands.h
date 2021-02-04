#pragma once

// 1254. Given a 2D grid consists of 0s (land) and 1s (water).
//       An island is a maximal 4-directionally connected group of 0s and a closed island is an island
//       totally (all left, top, right, bottom) surrounded by 1s. Return the number of closed islands.

// Solution: (complexity O(m * N))
// The exact same idea as problem #79.
// The only difference is when we mark an island visited, we never unmark it again.

SOLUTION_FOR_PROBLEM(1254, "Number of Closed Islands") {

bool is_closed(int x, int y, std::vector<std::vector<int>>& grid)
{
    if (x < 0 || x >= grid[0].size())
        return false;
    if (y < 0 || y >= grid.size())
        return false;
    if (grid[y][x] == 1)
        return true;

    grid[y][x] = 1;

    // We have to use 4 variables because we cannot afford to short circuit on false,
    // as we must fill all the islands to prevent ourselves from checking them again.
    bool closed1 = is_closed(x + 1, y, grid);
    bool closed2 = is_closed(x - 1, y, grid);
    bool closed3 = is_closed(x, y + 1, grid);
    bool closed4 = is_closed(x, y - 1, grid);

    return closed1 && closed2 && closed3 && closed4;
}

int closedIsland(std::vector<std::vector<int>>& grid) {
    int total_count = 0;

    for (int y = 0; y < static_cast<int>(grid.size()); ++y) {
        for (int x = 0; x < static_cast<int>(grid[0].size()); ++x) {
            if (grid[y][x] == 0)
                total_count += is_closed(x, y, grid);
        }
    }

    return total_count;
}

SOLVE()
{
    std::vector<std::vector<int>> vec = {
        { 0, 0, 1, 0, 0 },
        { 0, 1, 0, 1, 0 },
        { 0, 1, 1, 1, 0 }
    };

    auto res = closedIsland(vec);
}

}
