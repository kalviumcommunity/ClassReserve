#include<iostream>
#include "modules/room.h"
#include "modules/teacher.h"
#include "modules/reservation.h"

using namespace std;

Room create_room(){
    string roomtype_input;
    int capacity_input;

    cout<<"\n:::::Adding new Room:::::\n\n";
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

    cout<<"\n:::::Adding new Teacher:::::\n\n";
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

    cout<<"\n:::::Creating new Reservation:::::\n\n";
    cout<<"Please enter the date: ";
    cin>>date;
    cout<<"Please enter the hour: ";
    cin>>hour;

    Reservation res(room,tr,date,hour);
    return res;

}

int Room::count=0;
int Teacher::count=0;
int Reservation::count=0;

int main(){

    int room_count,tr_count,res_count;
    cout<<"Enter the number of rooms and number of teachers: ";
    cin>>room_count>>tr_count;

    Room* rooms[room_count];
    Teacher* teachers[tr_count];

    cout<<"\n::::::::::::::::::::::::::\n";
    cout<<":::::Creating "<<room_count<<" rooms:::::";
    cout<<"\n::::::::::::::::::::::::::\n\n";
    for(int i=0;i<room_count;i++){
        cout<<"\nRoom ID: "<<i;
        rooms[i]=new Room(create_room());
    }

    cout<<"\n:::::::::::::::::::::::::::::\n";
    cout<<":::::Creating "<<tr_count<<" teachers:::::";
    cout<<"\n:::::::::::::::::::::::::::::\n\n";
    for(int i=0;i<tr_count;i++){
        cout<<"\nTeacher ID: "<<i;
        teachers[i]=new Teacher(create_teacher());
    }

    cout<<"\n\nEnter the number of reservations: ";
    cin>>res_count;
    Reservation* reservations[res_count];

    cout<<"\n:::::::::::::::::::::::::::::::::\n";
    cout<<":::::Creating "<<res_count<<" reservations:::::";
    cout<<"\n:::::::::::::::::::::::::::::::::\n\n";
    for(int i=0;i<res_count;i++){
        cout<<"\nReservation ID: "<<i;
        int room_id,tr_id;
        cout<<"\nEnter room id(0 - "<<room_count-1<<") and teacher id(0 - "<<tr_count-1<<"): ";
        cin>>room_id>>tr_id;
        if(room_id<0||room_id>=room_count||tr_id<0||tr_id>=tr_count){
            throw(invalid_argument("Invalid teacher/room ID"));
        }
        // schedule conflicts to be handled in upcoming milestones
        reservations[i]=new Reservation(create_reservation(*rooms[room_id],*teachers[tr_id]));
    }

    for(auto res:reservations){
        res->view_reservation_detail();
    }

    cout<<"\n\n:::Total Count:::\nRoom: "<<Room::count<<"\nTeacher: "<<Teacher::count<<"\nReservarion: "<<Reservation::count;

    //delete dynamically allocated object arrays 
    for(int i=0;i<room_count;i++){
        delete rooms[i];
    }

    for(int i=0;i<tr_count;i++){
        delete teachers[i];
    }

    for(int i=0;i<res_count;i++){
        delete reservations[i];
    }

    return 0;
}