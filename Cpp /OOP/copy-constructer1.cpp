#include <iostream>
using namespace std;

class Person{
    int age;
    public:
        Person(int a){
            cout<<"Constructor called"<<endl;
            age = a;
        }
        Person(Person &copy){
            age = copy.age;
            cout<<"Copy Constructor Called"<<endl;
            copy.age++;
        }
        void show(){
            cout<<"Age = "<<age<<endl;
        }
};

int main(){
    Person p1(20);
    p1.show();
    Person p2 = p1;
    p2.show();
    p1.show();
    return 0;
}