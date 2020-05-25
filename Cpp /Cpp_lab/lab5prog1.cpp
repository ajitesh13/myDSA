/*
Develop a C++ program to perform addition, subtraction, multiplication and division of two user defined type variables. 
The user defined type variables contain two protected real numbers respectively. The binary +, -, * and / operators should be overloaded.
*/

#include <iostream>
using namespace std;

class A{
    protected:
        double x;
        double y;
    public:
        void show(){
            cout<<"x = "<<x;
            cout<<" y = "<<y<<endl;
        }
        A(){x = 0; y = 0;};
        A(double a, double b){
            x = a;
            y = b;
        }
        friend A operator+(A, A);
        friend A operator-(A, A);
        friend A operator*(A, A);
        friend A operator/(A, A);
};

A operator+(A lhs, A rhs){
    A temp;
    temp.x = lhs.x + rhs.x;
    temp.y = lhs.y + rhs.y;
    return temp;
}

A operator-(A lhs, A rhs){
    A temp;
    temp.x = lhs.x - rhs.x;
    temp.y = lhs.y - rhs.y;
    return temp;
}

A operator*(A lhs, A rhs){
    A temp;
    temp.x = lhs.x*rhs.x;
    temp.y = lhs.y*rhs.y;
    return temp;
}

A operator/(A lhs, A rhs){
    A temp;
    temp.x = lhs.x/rhs.x;
    temp.y = lhs.y/rhs.y;
    return temp;
}


int main(){
    A ob1(20,10);
    A ob2(2,1);
    A ob3 = ob1+ob2;
    ob3.show();
    A ob4 = ob1-ob2;
    ob4.show();
    A ob5 = ob1*ob2;
    ob5.show();
    A ob6 = ob1/ob2;
    ob6.show();
    return 0;
}


