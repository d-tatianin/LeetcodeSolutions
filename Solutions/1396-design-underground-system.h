#pragma once

// 1396. Description too long to fit here, go read the full version at https://leetcode.com/problems/design-underground-system/

// Solution: (complexity O(1))
// We utilize two hash maps, one where we keep the current traveling customers,
// and the other where we keep stats in the form of { string(begin_station + end_station) -> { total_time, time_traveled } }
// Then all we have to do to return the average between two station is look into our map at index string(station1 + station2)

SOLUTION_FOR_PROBLEM(1396, "Design Underground System") {

class UndergroundSystem {
public:
    void checkIn(int id, std::string stationName, int t) {
       m_customers[id] = { std::move(stationName), t }; 
    }
    
    void checkOut(int id, std::string stationName, int t) {
        auto& customer = m_customers[id];
        auto& stats = m_stats[customer.start_station + stationName];

        stats.total_time += t - customer.boarded_at;
        stats.times_traveled++;

        m_customers.erase(id);
    }

    double getAverageTime(std::string startStation, std::string endStation) {
        auto& this_route = m_stats[startStation + endStation];

        return static_cast<double>(this_route.total_time) / this_route.times_traveled;
    }

private:
    struct Stats {
      int total_time;
      int times_traveled;
    };

    struct Customer {
      std::string start_station;
      int boarded_at;
    };

    std::unordered_map<int, Customer> m_customers;
    std::unordered_map<std::string, Stats> m_stats;
};


SOLVE()
{
    // Example from leetcode
    UndergroundSystem s;

    s.checkIn(45, "Leyton", 3);
    s.checkIn(32, "Paradise", 8);
    s.checkIn(27, "Leyton", 10);
    s.checkOut(45, "Waterloo", 15);
    s.checkOut(27, "Waterloo", 20);
    s.checkOut(32, "Cambridge", 22);
    s.getAverageTime("Paradise", "Cambridge");
    s.getAverageTime("Leyton", "Waterloo");
    s.checkIn(10, "Leyton", 24);
    s.getAverageTime("Leyton", "Waterloo");
    s.checkOut(10, "Waterloo", 38);
    s.getAverageTime("Leyton", "Waterloo");
}

}
