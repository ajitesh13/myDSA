#include<iostream>
using namespace std;

class Student
{
   public:
        int id;
		double marks;
};

int main()
{
   Student s;
   s.id=1;
   s.marks=90.5;
   cout<<"ID="<<s.id<<endl;
   cout<<"Marks="<<s.marks<<endl;
   return 0;
}