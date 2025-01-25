#include "flights.h"
#include <iostream>

FlightMenager::FlightMenager()
{
    flights.push_back({1, "Warszawa", "Krakow", "2025-02-12", "12:00", 99.99});
    flights.push_back({2, "Warszawa", "Gdansk", "2025-02-12", "14:00", 199.99});
    flights.push_back({3, "Warszawa", "Wroclaw", "2025-02-12", "16:00", 299.99});
    flights.push_back({4, "Warszawa", "Poznan", "2025-02-12", "18:00", 399.99});
}

void FlightMenager::display_flights()
{
    for (auto f : flights)
    {
        std::cout << "Lot " << f.flight_id
                  << " z " << f.departure_city
                  << " do " << f.arrival_city
                  << " dnia " << f.date
                  << " o godzinie " << f.departure_time
                  << " w cenie " << f.price << " PLN" << std::endl;
    }
}

void FlightMenager::add_flight()
{
    flight f;
    f.flight_id = flights.size() + 1;
    std::cout << "Podaj miasto wylotu: ";
    std::cin >> f.departure_city;
    std::cout << "Podaj miasto przylotu: ";
    std::cin >> f.arrival_city;
    std::cout << "Podaj date: ";
    std::cin >> f.date;
    std::cout << "Podaj godzine wylotu: ";
    std::cin >> f.departure_time;
    std::cout << "Podaj cene: ";
    std::cin >> f.price;
    flights.push_back(f);
}