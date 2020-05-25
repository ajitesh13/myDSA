/* Initializing a const attribute */
#include<iostream>
using namespace std;

class Point
{
   const int x;
   
   public:
        Point(int a):x(a){}
		void show(){cout<<"x="<<x<<endl;}
};

int main()
{
   Point p(10);
   p.show();
   return 0;
}