#include <iostream>
using namespace std;

class Base{
    protected:
        int a;
    public:
        virtual void show()=0;
};

class Derived1:public Base{
    public:
        void show(){
            cout<<"This is Derived1 class"<<endl;
        }
};

class Derived2:public Base{
    public:
        void show(){
            cout<<"This is Derived2 class"<<endl;
        }
};

int main(){
    Base *bptr;
    Derived1 d1;
    bptr = &d1;
    bptr->show();
    Derived2 d2;
    bptr = &d2;
    bptr->show();
    return 0;
}
