/* Overloading the function call operator () */

#include<iostream>
using namespace std;

class Point
{
   int x,y,z;
   public:
        Point(){x=0;y=0;z=0;}
		void show()
		{
		   cout<<"x="<<x<<endl;
		   cout<<"y="<<y<<endl;
		   cout<<"z="<<z<<endl;
		}
		Point operator()(int i)
		{
		   x=i;
		   return *this;
		}
		Point operator()(int i,int j)
		{
		   x=i;y=j;
		   return *this;
		}
		Point operator()(int i,int j,int k)
		{
		   x=i;y=j;z=k;
		   return *this;
		}
};

int main()
{
   Point p;
   p.show();
   p(100);
   p.show();
   p(100,200);
   p.show();
   p(100,200,300);
   p.show();
   return 0;
}