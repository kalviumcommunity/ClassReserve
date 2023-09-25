#include<iostream>
#include "modules/room.h"
#include "modules/teacher.h"
#include "modules/reservation.h"

using namespace std;

int main(){

    string roomtype_input;
    int capacity_input;

    //sample inputs to initialize room
    cout<<"Please enter the room type: ";
    cin>>roomtype_input;
    cout<<"Please enter the capacity: ";
    cin>>capacity_input;

    //initialize an object of room type
    try{
        Room r1=Room(roomtype_input,capacity_input);
        r1.print_detail();
    }
    catch(const exception& err){
        cout<<err.what();
    }

    // declaring sample objects of each class
    // TODO: use array of objects wherever required, 
    // upcoming milestone(Array of Objects)
    Teacher t1;
    Reservation res1;

    return 0;
}