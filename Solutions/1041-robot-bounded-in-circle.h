#pragma once

// 1041. Description too long to fit here: https://leetcode.com/problems/robot-bounded-in-circle/

// Solution: (complexity O(N))
// Super simple idea, the robot is bounded if:
// - After executing the instructions it hasn't moved from 0, 0.
// OR
// - After executing the instructions it's still facing the initial direction.

SOLUTION_FOR_PROBLEM(1041, "Robot Bounded In Circle") {

bool isRobotBounded(std::string instructions) {
    int x = 0;
    int y = 0;
    
    enum class Direction {
        NORTH,
        SOUTH,
        EAST,
        WEST
    } direction = Direction::NORTH;

    auto turn = [](Direction current_direction, bool is_left)
    {
        if (current_direction == Direction::NORTH)
            return is_left ? Direction::WEST : Direction::EAST;
        else if (current_direction == Direction::SOUTH)
            return is_left ? Direction::EAST : Direction::WEST;
        else if (current_direction == Direction::EAST)
            return is_left ? Direction::NORTH : Direction::SOUTH;
        else if (current_direction == Direction::WEST)
            return is_left ? Direction::SOUTH : Direction::NORTH;

        return static_cast<Direction>(-1);
    };

    for (char c : instructions) {
        if (c == 'G') {
            if (direction == Direction::NORTH)
                y += 1;
            else if (direction == Direction::SOUTH)
                y -= 1;
            else if (direction == Direction::EAST)
                x += 1;
            else if (direction == Direction::WEST)
                x -= 1;
        } else {
            direction = turn(direction, c == 'L');
        }
    }

    return direction != Direction::NORTH || (x == 0 && y == 0);
}

SOLVE()
{
    auto res = isRobotBounded("GGLLGG");
}

}
