#include<iostream>
using namespace std;

class Person
{
    int age;
	public:
	Person(int a){cout<<"Constructor called"<<endl;
	              age=a;}
	Person(const Person &copy){cout<<"Copy constructor called"<<endl;
	                     age=copy.age;}
	void show(){cout<<"Age = "<<age<<endl;}
};

int main()
{
   const Person p1(20);
   Person p2=p1;
   p2.show();
   return 0;
}