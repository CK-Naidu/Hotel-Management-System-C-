#include <iostream>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include "utils.h"

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void intro() {
    cout << "\t\t\t\tC++ Project On Hotel Management System" << endl;
    cout << "\n\t\t\t\tPresented by: Kandi Chenna Kesava Naidu\n";
}

void header() {
    clearScreen();
    cout << "\n\t\t\t\tCK_Naidu ***** Hotel\n";
    cout << "\t\t\t\t-------------------------\n";
}

void loadingTime() {
    cout << "\n\tConnecting to server. Syncing data";
    for (int i = 0; i < 5; ++i) {
        cout << ".";
#ifdef _WIN32
        Sleep(500);
#else
        usleep(500000);
#endif
    }
    cout << "\n";
}
