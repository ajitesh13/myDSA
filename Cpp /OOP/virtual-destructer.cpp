/*
    if normal base class destructor is provided then only
    base class destructer is working and the derived class 
    destructor is not working, and to make it work we have to provide the 
    virtual base class destructer
*/



#include <iostream>
using namespace std;

class Base{
    public:
        Base(){
            cout<<"Base class constructor"<<endl;
        }
        virtual ~Base(){
            cout<<"Base class Destrcuter"<<endl;
        }
};

class Derived:public Base{
    public:
        Derived(){
            cout<<"Derived class Constructor"<<endl;
        }
        ~Derived(){
            cout<<"Derived class destructor"<<endl;
        }
};

int main(){
    Base *pb;
    pb = new Derived;
    delete pb;
    return 0;
}