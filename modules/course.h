using namespace std;

// Abstract class
class Course{
    protected:
    string name;
    int years;

    public:

    virtual void printDetail()=0;

    void getInput(){
        cout<<"Please enter the course name: ";
        cin.ignore();
        getline(cin,this->name);
        cout<<"Please enter the number of years: ";
        cin>>this->years;
    }
};

class Bachelors: public Course{
    public:
    void printDetail() override {
        cout<<"\n"<<this->name<<" is a Bachelors course that spans over "<<this->years<<" years.\nThe minimum eligibility for this course is 12th grade.\n";
    }
};

class Masters: public Course{
    public:
    void printDetail() override {
        cout<<"\n"<<this->name<<" is a Masters course that spans over "<<this->years<<" years.\nThe minimum eligibility for this course is a bachelor's degree.\n";
    }
};