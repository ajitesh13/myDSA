#include<iostream>
using namespace std;

class Student
{
   private:
        int id;
		double marks;
   public:
	    void get(int i, double m);
		void display();
};

void Student::get(int i, double m)
{
   id=i;
   marks=m;
}

void Student::display()
{
   cout<<"ID of a student="<<id<<endl;
   cout<<"Marks of a student="<<marks<<endl;
}

int main()
{
   Student s;
   int stud_id;
   double stud_marks;
   cout<<"Enter ID of a student"<<endl;
   cin>>stud_id;
   cout<<"Enter marks of a student"<<endl;
   cin>>stud_marks;
   s.get(stud_id,stud_marks);
   s.display();
   return 0;
}