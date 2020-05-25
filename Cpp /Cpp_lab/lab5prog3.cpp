
/*
Develop a C++ program where a user defined type variable can be subtracted 
from an integer value and vice versa. The user defined type variable should 
contain only a single integer attribute under protected visibility.
*/

#include <iostream>
using namespace std;

class User{
    protected:
        int a;

    public:
        User(){
            cout<<"Enter value for objects:";
            cin>>a;
        }
        friend int operator-(User, int);
        friend int operator-(int User);
};

int operator-(User u, int x){
    return (u.a - x);
}

int operator-(int x, User u){
    return (x - u.a);
}

int main(){
    int res, res1, inp;
    User ob1;
    cout<<"Enter value:";
    cin>>inp;
    res = ob1 - inp;
    res1 = inp -ob1;
    cout<<"Result 1: "<<res<<endl;
    cout<<"Result 2: "<<res1<<endl;
    return 0;
}