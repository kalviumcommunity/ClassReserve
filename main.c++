#include<iostream>
using namespace std;

class Room{
    private:
    string room_type;
    int capacity;

    public:
    Room(string room_type,int capacity){
        if(!(room_type=="classroom"||room_type=="lecture_hall")){
            throw "Invalid Room Type";
        }
        this->room_type=room_type;
        this->capacity=capacity;
    }
    void print_detail(){
        cout<<"\nRoom Type: "<<this->room_type<<"\nCapacity: "<<this->capacity;
    }
};

class Teacher{
    private:
    string name;
    string subject;

    // TODO: define cosntructors 
    // - in upcoming milestone(Constructors and Destructors)
};

class Reservation{
    private:
    Room *room;
    Teacher teacher;
    // epoch timestamps to be stored as string
    string from_time;
    string to_time;

    public:
    Reservation(){
        // TODO: define copy constructors and get values from params
        // to be covered in upcoming milestone(Constructors and Destructors)
        // hard coding values for Milestone #1
        room=new Room("classroom",30);
    }
};



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
    catch(char const *err){
        cout<<err;
    }

    // declaring sample objects of each class
    // TODO: use array of objects wherever required, 
    // upcoming milestone(Array of Objects)
    Teacher t1;
    Reservation res1;

    return 0;
}