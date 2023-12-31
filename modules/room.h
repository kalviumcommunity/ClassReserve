using namespace std;

class Room{
    private:
    string room_type;
    int capacity;
    static int count;

    public:
    Room(string room_type,int capacity){
        if(!(room_type=="classroom"||room_type=="lecture_hall")){
            throw invalid_argument("Invalid Room Type");
        }
        if(capacity<1){
            throw invalid_argument("Minimum Capacity is 1");
        }
        count++;
        this->room_type=room_type;
        this->capacity=capacity;
    }

    Room(const Room &room){
        this->room_type=room.room_type;
        this->capacity=room.capacity;
    }

    void print_detail(){
        cout<<"\nRoom Type: "<<this->room_type<<"\nCapacity: "<<this->capacity;
    }

    static int get_count(){
        return count;
    }
    
};
