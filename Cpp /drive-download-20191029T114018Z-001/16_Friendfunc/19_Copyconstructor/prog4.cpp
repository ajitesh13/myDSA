#include<iostream>
using namespace std;

class Person
{
    int *age;
	public:
	Person(int a){age=new int[3];
	              age[0]=10;
				  age[1]=20;
	              age[2]=30;}
	void show(){cout<<"Age = "<<age[0]<<endl;}
	~Person(){delete []age;}
	/*Person(const Person &copy)
	{
		age=copy.age;
	}*/ //shallow copy
	Person(const Person &copy)
	{ //age=new int;
	  age[0]=copy.age[0];
	  age[1]=copy.age[1];
	  age[2]=copy.age[2];
	}//deep copy
};

int main()
{
   Person p1(20);
   p1.show();
   {
      Person p2=p1;
      p2.show();
   }
   p1.show();
   return 0;
}