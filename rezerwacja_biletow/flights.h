#ifndef flights_h
#define flights_h

#include <string>
#include <vector>

struct flight
{
    int flight_id;
    std::string departure_city;
    std::string arrival_city;
    std::string date;
    std::string departure_time;
    double price;
};

class FlightMenager
{
private:
    std::vector<flight> flights;

public:
    FlightMenager();
    void display_flights();
    void add_flight();
};

#endif
