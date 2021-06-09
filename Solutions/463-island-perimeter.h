#pragma once

// 463. Description too long to fit here https://leetcode.com/problems/island-perimeter/

// Solution: (complexity O(X * Y))
// The exact same idea as problem #79 and #1254
// Do a DFS while marking islands as visited. If we encouter water
// we increment the counter by 1.

SOLUTION_FOR_PROBLEM(463, "Island Perimeter") {

int get_total_for(int x, int y, std::vector<std::vector<int>>& grid)
{
    if (x >= grid[0].size() || x < 0)
        return 1;
    if (y >= grid.size() || y < 0)
        return 1;
    if (grid[y][x] == 3)
        return 0;
    if (grid[y][x] == 0) {
        return 1;
    }

    // mark this island as visited
    grid[y][x] = 3;

    return get_total_for(x, y - 1, grid) + get_total_for(x, y + 1, grid)
         + get_total_for(x - 1, y, grid) + get_total_for(x + 1, y, grid);
}

int islandPerimeter(std::vector<std::vector<int>>& grid) {
    int total = 0;

    for (size_t y = 0; y < grid.size(); ++y) {
        for (size_t x = 0; x < grid[0].size(); ++x) {
            if (grid[y][x] == 1)
                total += get_total_for(static_cast<int>(x), static_cast<int>(y), grid);
        }
    }

    return total;
}

SOLVE()
{
    std::vector<std::vector<int>> vec = {
        { 0, 1, 0, 0 },
        { 1, 1, 1, 0 },
        { 0, 1, 0, 0 },
        { 1, 1, 0, 0 }
    };

    auto res = islandPerimeter(vec);
}

}
