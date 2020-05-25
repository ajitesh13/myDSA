
/*
Create a class named as Test with two integer attributes x and y.
 Provide an operator function to check whether two objects of the class Test are equal or not. The comparison operator (= =) should be overloaded.
 */

#include <iostream>
using namespace std;

class test{
    private:
        int x;
        int y;
    public:
        test(){x = 0; y = 0;}
        test(int a, int b){
            x = a;
            y = b;
        }
        test(){
            cin>>x;
            cin>>y;
        }
        friend void operator==(A, A);
};

void operator==(){
    if(lhs.x == rhs.x){
        cout<<"x is equal"<<endl;
    }
    else{
        cout<<"x is not equal"<<endl;
    }
    if(lhs.y == rhs.y){
        cout<<"y is equal"<<endl;
    }
    else{
        cout<<"y is not equal"<<endl;
    }
}

int main(){
    test t1(2, 3);
    test t2 == t1;
    return 0;
}