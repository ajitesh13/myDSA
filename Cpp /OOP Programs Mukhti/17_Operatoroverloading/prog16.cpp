/* Conversion operator function */

#include<iostream>
using namespace std;

class Point
{
   int x;
   public:
        Point(int a)
		{x=a;}
		void show(){cout<<"x="<<x<<endl;}
		operator int()
		{
		   return x;
		}
};

int main()
{
   Point p=100;
   p.show();
   int i=p;
   cout<<"i="<<i<<endl;
   return 0;
}