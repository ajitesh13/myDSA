/* Explicit constructor is required when we don't want 
a type conversion from primitive type to user defined type  */
#include<iostream>
using namespace std;

class Point
{
   int x;
   public:
        explicit Point(int a){x=a;}
		void show(){cout<<"x="<<x<<endl;}
};

int main()
{
   Point p(10);
   Point p2=100;// not allowed
   p.show();
   // Point pp=100 will not work
   return 0;
}