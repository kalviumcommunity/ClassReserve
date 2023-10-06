#include<iostream>
#include "modules/room.h"
#include "modules/teacher.h"
#include "modules/reservation.h"

using namespace std;

Room create_room(){
    string roomtype_input;
    int capacity_input;

    cout<<"\n\n:::::Adding new Room:::::\n";
    cout<<"Please enter the room type: ";
    cin>>roomtype_input;
    cout<<"Please enter the capacity: ";
    cin>>capacity_input;

    Room room(roomtype_input,capacity_input);
    return room;
}

Teacher create_teacher(){
    string name;
    string department;

    cout<<"\n\n:::::Adding new Teacher:::::\n";
    cout<<"Please enter the teacher name: ";
    cin.ignore();
    getline(cin,name);
    cout<<"Please enter the department: ";
    getline(cin,department);

    Teacher tr(name,department);
    return tr;
}

Reservation create_reservation(Room room, Teacher tr){
    string date;
    int hour;

    cout<<"\n\n:::::Creating new Reservation:::::\n";
    cout<<"Please enter the date: ";
    cin>>date;
    cout<<"Please enter the hour: ";
    cin>>hour;

    Reservation res(room,tr,date,hour);
    return res;

}

int main(){

    // declaring single object of each class
    // TODO: use array of objects wherever required, 
    // upcoming milestone(Array of Objects)

    Room r1=create_room();
    Teacher t1=create_teacher();
    Reservation res1=create_reservation(r1,t1);

    res1.view_reservation_detail();

    return 0;
}