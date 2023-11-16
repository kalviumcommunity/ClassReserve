using namespace std;

// Interface
class Staff{
    public:
    virtual void getInput()=0;
    virtual void showDetail()=0;
};

class Admin: public Staff{
    private:
    int id;
    string name;
    string mobile;

    public:
    void getInput() override {
        cout<<"\n\n:::::Adding new Admin:::::\n";
        cout<<"Please enter the id: ";
        cin>>id;
        cout<<"Please enter the name: ";
        cin.ignore();
        getline(cin,this->name);
        cout<<"Please enter the mobile number: ";
        getline(cin,this->mobile);
    }

    void showDetail() override{
        cout<<"\n\nAdmin Staff - "<<this->id<<" - "<<this->name<<" - "<<this->mobile<<"\n";
    }

};

class HouseKeeping: public Staff{
    private:
    int id;
    string name;
    int floor;

    public:
    void getInput() override {
        cout<<"\n\n:::::Adding new House Keeping Staff:::::\n";
        cout<<"Please enter the id: ";
        cin>>id;
        cout<<"Please enter the name: ";
        cin.ignore();
        getline(cin,this->name);
        cout<<"Please enter the assigned floor: ";
        cin>>this->floor;
    }

    void showDetail() override{
        cout<<"\n\nHouse Keeping Staff - "<<this->id<<" - "<<this->name<<" - Floor "<<this->floor<<"\n";
    }

};

