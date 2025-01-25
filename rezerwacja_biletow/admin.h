#ifndef admin_h
#define admin_h

#include <string>
#include <iostream>

class Admin
{
private:
    std::string admin_password;
    bool is_admin;
    int option;

public:
    Admin();
    bool is_admin_logged();
    void display_admin_menu();
};

#endif