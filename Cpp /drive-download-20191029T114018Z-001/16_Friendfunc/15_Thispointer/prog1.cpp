/* this pointer points to the current object
for which the member function has been called.
this pointer is implicitly present in every
member function of a class and it is the first 
argument of every member function of a class
except static member functions which do not have
a this pointer. */

#include<iostream>
using namespace std;

class Point
{
   int x;
   int y;
   public:
         void get(int a, int b)
		 {
		    this->x=a;//same as x=a
			this->y=b;//same as y=b
		 }
		 void display()
		 {
		    cout<<"x="<<x<<endl;//same as this->x
			cout<<"y="<<y<<endl;//same as this->y
		 }
};

int main()
{
   Point p;
   p.get(10,20);
   p.display();
   return 0;
}