#include "flights.h"
#include "admin.h"
#include <iostream>
#include <string>

int main()
{
    FlightMenager FlightMenager;
    Admin Admin;
    int user_action_choice;
    std::string admin_password = "admin";

    while (user_action_choice != 5)
    {
        std::cout << "System rezerwacji biletow lotniczych" << std::endl;
        std::cout << "1. Dostepne loty" << std::endl;
        std::cout << "2. Rezerwacja biletu" << std::endl;
        std::cout << "3. Anulowanie rezerwacji" << std::endl;
        std::cout << "4. Wyswietl rezerwacje" << std::endl;
        std::cout << "5. Wyjscie" << std::endl;
        std::cout << "6. Administarator" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> user_action_choice;

        switch (user_action_choice)
        {
        case 1:
        {
            std::cout << "Dostepne loty:" << std::endl;
            FlightMenager.display_flights();
            break;
        }

        case 6:
        {
            if (Admin.is_admin_logged())
            {
                Admin.display_admin_menu();
            }
            break;
        }
        }
    }
    return 0;
}