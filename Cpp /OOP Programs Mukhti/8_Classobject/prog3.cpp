#include<iostream>
using namespace std;

class Student
{
   protected:
        int id;
		double marks;
};

int main()
{
   Student s;
   s.id=1;//Will generate an error
   s.marks=90.5;//Will generate an error
   cout<<"ID="<<s.id<<endl;
   cout<<"Marks="<<s.marks<<endl;
   return 0;
}