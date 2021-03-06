#include<iostream>
using namespace std;

class Student
{
   private:
        int id;
		double marks;
   public:
	    void get();
		void display();
};

void Student::get()
{
   cout<<"Enter ID of a student"<<endl;
   cin>>id;
   cout<<"Enter marks of a student"<<endl;
   cin>>marks;
}

void Student::display()
{
   cout<<"ID of a student="<<id<<endl;
   cout<<"Marks of a student="<<marks<<endl;
}

int main()
{
   Student s;
   s.get();
   s.display();
   return 0;
}