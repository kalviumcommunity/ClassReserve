using namespace std;

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