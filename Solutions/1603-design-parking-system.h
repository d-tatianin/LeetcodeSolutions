#pragma once

// 1603. Description too long to fit here https://leetcode.com/problems/design-parking-system/

// Solution: (complexity O(1))
// Just use an array.

SOLUTION_FOR_PROBLEM(1603, "Design Parking System") {

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small)
       : sizes { big, medium, small } 
    {
    }

    bool addCar(int carType) {
        if (sizes[carType - 1]-- <= 0)
            return false;

        return true;
    }

private:
    int sizes[3];
};

SOLVE()
{
    ParkingSystem parkingSystem(1, 1, 0);
    parkingSystem.addCar(1); // return true because there is 1 available slot for a big car
    parkingSystem.addCar(2); // return true because there is 1 available slot for a medium car
    parkingSystem.addCar(3); // return false because there is no available slot for a small car
    parkingSystem.addCar(1); // return false because there is no available slot for a big car. It is already occupied.
}

}
