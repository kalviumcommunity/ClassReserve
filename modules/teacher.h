using namespace std;

class Teacher{
    private:
    string name;
    string department;

    public:
    static int count;
    Teacher(string name, string department){
        if(name.length()<3||department.length()<2){
            throw invalid_argument("Invalid Name/Dept.");
        }
        count++;
        this->name=name;
        this->department=department;
    }

    void print_detail(){
        cout<<"\nTeacher Name: "<<this->name<<"\nDepartment: "<<this->department;
    }

    Teacher(const Teacher &tr){
        this->name=tr.name;
        this->department=tr.department;
    }
   
};