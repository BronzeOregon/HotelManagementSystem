#include <iostream>
#include <string>
#include <conio.h>
#define max 100

using namespace std;

class Guest{
    string name;
    string address;
    string phone;
    string checkInDate;
    string checkOutDate;
    float total;
    int id;

public:
    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Guest::name = name;
    }

    const string &getAddress() const {
        return address;
    }

    void setAddress(const string &address) {
        Guest::address = address;
    }

    const string &getPhone() const {
        return phone;
    }

    void setPhone(const string &phone) {
        Guest::phone = phone;
    }

    const string &getCheckInDate() const {
        return checkInDate;
    }

    void setCheckInDate(const string &checkInDate) {
        Guest::checkInDate = checkInDate;
    }

    const string &getCheckOutDate() const {
        return checkOutDate;
    }

    void setCheckOutDate(const string &checkOutDate) {
        Guest::checkOutDate = checkOutDate;
    }

    float getTotal() const {
        return total;
    }

    void setTotal(float total) {
        Guest::total = total;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Guest::id = id;
    }
};

class Room{
    int beds;
    char bedSize;
    int roomNum;
    int rate;
    bool booked = false;

public:class Guest guest;

public:int getRoomNum(){
        return this->roomNum;
    }

public:void setRoomNum(int input){
        this->roomNum = input;
    }

    bool getBooked(){
        return this->booked;
    }

    void setBooked(bool b) {
        this->booked=b;

    }
};

void availableRooms(Room rooms[]){
    for(int i = 0; i <60; i++){
        if(!rooms[i].getBooked()){
            cout<< "Room Number: " + to_string(rooms[i].getRoomNum()) + " is available.\n";
        }
    }
}

void mainMenu(Room rooms[]){
    cout<< "Welcome to the Mediocre Hotel Management System!\n";
    bool cont = true;

    while(cont) {
        cout << "Please choose one of the following options!\n";
        cout << "To return a list of available rooms, please enter '1'.\n";
        cout << "To check-in a guest, please enter '2'.\n";
        cout << "To check-out a guest, please enter '3'.\n";
        cout << "To view more info about an available room, please enter '4'.\n";
        cout << "To exit the program, please enter '0'.\n";
        char input;
        cin >> input;
        if (input == '1') {
            availableRooms(rooms);
        } else if (input == '2') {
            cout << "Please enter the room number the guest will be checking into.\n";
            int room;
            cin >> room;
            int roomArr;

            for (int i = 0; i < 60; i++) {
                if (rooms[i].getRoomNum() == room) {
                    roomArr = i;
                }
//                else {
//                    cout << "There was an error. Please try again.";
//                }
            }

            cout << "Please enter the guest's first name.\n";
            string firstName;
            cin >> firstName;

            cout << "Please enter the guest's last name.\n";
            string lastName;
            cin >> lastName;

            string name = firstName + " " + lastName;

            rooms[roomArr].guest.setName(name);

            cout << "Please enter the guest's phone number.\n";
            string phone;
            cin >> phone;

            rooms[roomArr].guest.setPhone(phone);

            cout << "Please enter the guest's check-in date. (Format: DD/MM/YYYY)\n";
            string checkIn;
            cin >> checkIn;

            rooms[roomArr].guest.setCheckInDate(checkIn);

            cout << "Please enter the guest's check-out date. (Format: DD/MM/YYYY)\n";
            string checkOut;
            cin >> checkOut;

            rooms[roomArr].guest.setCheckOutDate(checkOut);

            rooms[roomArr].setBooked(true);

            cout << "Booking made for guest: " + rooms[roomArr].guest.getName() + ". Reachable at: " + rooms[roomArr].guest.getPhone() + ".\n";
            cout << "Check-in is on " + rooms[roomArr].guest.getCheckInDate() + " and check-out will be on " + rooms[roomArr].guest.getCheckOutDate() + ".\n";

        }


        if (input == 0) {
            cont = false;
        }
    }
}



int main() {

    Room rooms[60];
//        for (int i = 1; i <= 3; i++) {
//            for (int j = 1; j < 21; j++) {
//                rooms[(i*j)-1].setRoomNum((i*100)+j);
//            }
//        }

        for(int i = 1; i < 61; i++){

            if(i<21){
                rooms[i-1].setRoomNum(100+i);
            } else if(i<41){
                rooms[i-1].setRoomNum(200+(i-20));
            } else{
                rooms[i-1].setRoomNum(300+(i-40));
            }

        }



//    for(int i = 0;i<60;i++){
//        std::cout << "Room number: " + to_string(rooms[i].getRoomNum()) + " ";
//    }

    mainMenu(rooms);
    return 0;
}
