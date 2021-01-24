#pragma once

// 1344. Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.

// Solution: (complexity O(1))
// This problem is nothing but simple math and logic, not really even related to programming
// Basic idea is we know a clock is 360 degrees, becaues it's a circle. We also know that
// 60 minutes have to pass for the minute hand to make a full rotation, therefore we can deduce
// that 360 / 60 is the amount of degrees a minute hand moves per minute. Using the exact same logic
// we can deduce that the hour hand makes a 360 / 12 degrees rotation per hour. We can also easily
// calculate the rotation the hour hand makes each minute by doing 360 / (12 * 60). That's it,
// now all that's left is a few simple equations to calculate the angle between the two hands.

PROBLEM(1344, "Angle Between Hands of a Clock") {

double angleClock(int hour, int minutes) {
    int degrees_per_minute_for_minute_hand = 360 / 60;

    double degrees_per_hour_for_hour_hand = 360 / 12;
    double degrees_per_minute_for_hour_hand = 360.0 / (12 * 60);

    double hour_hand_degrees = degrees_per_hour_for_hour_hand * hour + degrees_per_minute_for_hour_hand * minutes;
    int minute_hand_degrees = degrees_per_minute_for_minute_hand * minutes;

    auto angle = abs(hour_hand_degrees - minute_hand_degrees);

    return std::min(angle, 360 - angle);
}

TRY_SOLVE()
{
    auto res = angleClock(12, 30);
}

}
