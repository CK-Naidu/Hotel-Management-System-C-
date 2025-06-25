#ifndef HOTEL_H
#define HOTEL_H

class Hotel {
private:
    int room_no;
    char name[30];
    char address[50];
    char phone[15];
    int days;
    float fare;

public:
    void mainMenu();
    void add();
    void display();
    void rooms();
    void edit();
    int check(int);
    void modify(int);
    void deleteRec(int);
};

#endif
