#include<iostream>
using namespace std;

class Person
{
    int age;
	public:
	Person(int a){cout<<"Constructor called"<<endl;
	              age=a;}
	Person(Person &copy){cout<<"Copy constructor called"<<endl;
	                     age=copy.age;}
	void show(){cout<<"Age = "<<age<<endl;}
};

void display(Person temp)
{
	temp.show();
}
int main()
{
   Person p1(20);
   p1.show();
   Person p2=p1;
   p2.show();
   Person p3(p2);
   p3.show();
   display(p3);
   return 0;
}