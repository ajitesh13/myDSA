/*
    if a pointer for base class is created and the address of the derived class
    is assigned to it. still it will only access the function of base class 
    not from the derived one.
*/

// #include <iostream>
// using namespace std;

// class Base{
//     public:
//         int x;
//     public:
//         void show(){
//             x = 100;
//             cout<<"x = "<<x<<endl;
//         }
// };

// class Derived:public Base{
//     public:
//         int y;
//         void show(){
//             x = 200;
//             y = 400;
//             cout<<"x = "<<x<<endl;
//             cout<<"y = "<<y<<endl;
//         }
// };

// int main(){
//     Base ob, *bptr;
//     bptr = &ob;
//     bptr->show();
//     Derived d;
//     bptr = &d;
//     bptr->show();
//     return 0;
// }

/*
    This problem is solved by using virtual function
*/

#include <iostream>
using namespace std;

class Base{
    public:
        int x;
    public:
        virtual void show(){
            x = 100;
            cout<<"x = "<<x<<endl;
        }
};

class Derived:public Base{
    public:
        int y;
        void show(){
            x = 200;
            y = 400;
            cout<<"x = "<<x<<endl;
            cout<<"y = "<<y<<endl;
        }
};

int main(){
    Base ob, *bptr;
    bptr = &ob;
    bptr->show();
    Derived d;
    bptr = &d;
    bptr->show();
    return 0;
}