#include <iostream>
using namespace std;

class A{
        int x, y;
    public:
        A(int i);
        A(int i, int j);
        ~A();
        void display();
};

A::A(int i){
    x = i;
    y = 5;
}

A::A(int i, int j){
    x = i;
    y = j;
}

A::~A(){
    cout<<"The object is destroyed!"<<endl;
}

void A::display(){
    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;
}

int main(){
    A ob1(20);
    A ob2(10, 40);
    A ob3;
    ob1.display();
    ob2.display();
    ob3.display();
    return 0;
}