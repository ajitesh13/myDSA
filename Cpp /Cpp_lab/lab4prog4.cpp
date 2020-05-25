/*
With an appropriate example show that virtual functions are inherited in 
multi-level inheritance.
*/

#include <iostream>
using namespace std;

class Base{
    public:
        virtual void show(){
            cout<<"This is the Base Class Function";
        }
};

class Derived1:public Base{
    public:
        void show(){
            cout<<"This is the Derived1 class Function";
        }
};

class Derived2:public Derived1{
    public:
        void show(){
            cout<<"This is the Derived2 class Function";
        }
};

int main(){
    Base *bptr;
    Base b;
    bptr = &b;
    bptr->show();
    Derived1 d1;
    bptr = &d1;
    bptr->show();
    Derived2 d2;
    bptr = &d2;
    bptr->show();
    return 0;    
}