using namespace std;

class Reservation{
    private:
    Room *room;
    Teacher *teacher;

    string date; //dd-mm-yyyy
    int hour; // hour in 24hr format

    public:
    static int count;
    Reservation(Room room, Teacher teacher,string date, int hour){
        this->room=new Room(room);
        this->teacher=new Teacher(teacher);
        if(date.length()!=10||date[2]!='-'||date[5]!='-'){
            throw invalid_argument("Invalid Date!");
        }
        this->date=date;
        if(hour<0||hour>23){
            throw invalid_argument("Invalid hour! (Use 0-23)");
        };
        this->hour=hour;
        count++;
    }

    void view_reservation_detail(){
        cout<<"\n\n:::Reservation Details:::\n";
        room->print_detail();
        teacher->print_detail();
        cout<<"\nDate: "<<this->date<<"\nHour: "<<this->hour<<endl;
    }

    ~Reservation(){
        delete room;
        delete teacher;
    }
};