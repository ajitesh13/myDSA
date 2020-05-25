/*
   Friend Function can access all the members of the class to which they are 
   friends, not directly but using the object of the rspective class, as this 
   doesnt have this pointer
*/


#include <iostream>
using namespace std;

class A{
        int x;
    public:
        A(int i){
            x = i;
        }
        friend void func(A ob);
};

void func(A ob){
    cout<<"Square of x = "<<ob.x*ob.x<<endl;
}

int main(){
    A ob1(5);
    func(5);
    return 0;
}