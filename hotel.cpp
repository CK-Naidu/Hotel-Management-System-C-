#include <iostream>
#include <fstream>
#include <cstring>
#include "hotel.h"
#include "utils.h"

using namespace std;

void Hotel::mainMenu() {
    int choice = 0;
    while (choice != 5) {
        clearScreen();
        header();
        cout << "\n\t\t1. Book a Room";
        cout << "\n\t\t2. View Your Record";
        cout << "\n\t\t3. View Allotted Rooms";
        cout << "\n\t\t4. Edit Your Record";
        cout << "\n\t\t5. Exit";
        cout << "\n\n\t\tEnter your choice (1-5): ";
        cin >> choice;
        switch (choice) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: rooms(); break;
            case 4: edit(); break;
            case 5: break;
            default: cout << "\n\t\tInvalid Choice. Try Again."; break;
        }
        cout << "\n\t\tPress Enter to continue...";
        cin.ignore(); cin.get();
    }
}

void Hotel::add() {
    clearScreen();
    header();
    int r;
    ofstream fout("data/Record.dat", ios::app | ios::binary);
    cout << "\n\tEnter Room Number: ";
    cin >> r;
    if (check(r)) {
        cout << "\n\tRoom already booked.";
        return;
    }
    room_no = r;
    cout << "\tName: "; cin >> name;
    cout << "\tAddress: "; cin >> address;
    cout << "\tPhone: "; cin >> phone;
    cout << "\tNumber of Days: "; cin >> days;
    fare = days * 5000;
    fout.write((char*)this, sizeof(Hotel));
    fout.close();
    cout << "\n\tRoom successfully booked!";
}

void Hotel::display() {
    clearScreen();
    header();
    ifstream fin("data/Record.dat", ios::in | ios::binary);
    int r, found = 0;
    cout << "\n\tEnter Room Number: "; cin >> r;
    while (fin.read((char*)this, sizeof(Hotel))) {
        if (room_no == r) {
            cout << "\n\tRoom No: " << room_no;
            cout << "\n\tName: " << name;
            cout << "\n\tAddress: " << address;
            cout << "\n\tPhone: " << phone;
            cout << "\n\tDays: " << days;
            cout << "\n\tFare: " << fare;
            found = 1;
            break;
        }
    }
    fin.close();
    if (!found)
        cout << "\n\tRecord not found.";
}

void Hotel::rooms() {
    clearScreen();
    header();
    ifstream fin("data/Record.dat", ios::in | ios::binary);
    cout << "\n\tAllotted Rooms:\n";
    while (fin.read((char*)this, sizeof(Hotel))) {
        cout << "\n\tRoom No: " << room_no;
        cout << " | Name: " << name;
        cout << " | Phone: " << phone;
    }
    fin.close();
}

void Hotel::edit() {
    clearScreen();
    header();
    int choice, r;
    cout << "\n\t1. Modify Record\n\t2. Delete Record\n\tEnter your choice: ";
    cin >> choice;
    cout << "\n\tEnter Room Number: "; cin >> r;
    if (choice == 1) modify(r);
    else if (choice == 2) deleteRec(r);
    else cout << "\n\tInvalid choice.";
}

int Hotel::check(int r) {
    ifstream fin("data/Record.dat", ios::in | ios::binary);
    while (fin.read((char*)this, sizeof(Hotel))) {
        if (room_no == r) {
            fin.close();
            return 1;
        }
    }
    fin.close();
    return 0;
}

void Hotel::modify(int r) {
    fstream file("data/Record.dat", ios::in | ios::out | ios::binary);
    long pos;
    while (!file.eof()) {
        pos = file.tellg();
        file.read((char*)this, sizeof(Hotel));
        if (room_no == r) {
            cout << "\tNew Name: "; cin >> name;
            cout << "\tNew Address: "; cin >> address;
            cout << "\tNew Phone: "; cin >> phone;
            cout << "\tNew Days: "; cin >> days;
            fare = days * 5000;
            file.seekp(pos);
            file.write((char*)this, sizeof(Hotel));
            cout << "\n\tRecord updated.";
            break;
        }
    }
    file.close();
}

void Hotel::deleteRec(int r) {
    ifstream fin("data/Record.dat", ios::in | ios::binary);
    ofstream fout("data/temp.dat", ios::out | ios::binary);
    while (fin.read((char*)this, sizeof(Hotel))) {
        if (room_no != r)
            fout.write((char*)this, sizeof(Hotel));
    }
    fin.close();
    fout.close();
    remove("data/Record.dat");
    rename("data/temp.dat", "data/Record.dat");
    cout << "\n\tRecord deleted.";
}