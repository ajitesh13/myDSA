#include<iostream>
using namespace std;

class Person
{
    int age;
	public:
	Person(int a){cout<<"Constructor called"<<endl;
	              age=a;}
	Person(const Person &copy){cout<<"Copy constructor called"<<endl;
	                     age=copy.age; copy.age++;}
	void show(){cout<<"Age = "<<age<<endl;}
};

int main()
{
   Person p1(20);
   p1.show();
   Person p2=p1;
   p2.show();
   p1.show();
   return 0;
}