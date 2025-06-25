#include <iostream>
#include <string>
#include "hotel.h"
#include "utils.h"

using namespace std;

bool login() {
    string username, password;

    cout << "\n\n\t\tLogin Required\n";
    cout << "\t\t--------------\n";
    cout << "\tUsername (admin): ";
    cin >> username;
    cout << "\tPassword (pass): ";
    cin >> password;

    if (username == "admin" && password == "pass") {
        cout << "\n\n\t\tLogin Successful!\n";
        return true;
    } else {
        cout << "\n\n\t\tInvalid Credentials. Exiting...\n";
        return false;
    }
}

int main() {
    clearScreen();
    intro();
    loadingTime();

    if (!login())
        return 1;

    Hotel h;
    h.mainMenu();

    clearScreen();
    cout << "\n\n\t\tThank you for using CK_Naidu Hotel Management System!\n";
    cout << "\t\tGoodbye!\n\n";

    return 0;
}
