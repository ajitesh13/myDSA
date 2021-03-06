/* Advantages of overloading a binary operator using non-member operator function */

#include<iostream>
using namespace std;

class Point
{
    int x;
	public:
	      Point(){x=0;}
		  Point(int a){x=a;}
		  friend int operator+(int lhs, Point rhs)
          {
		     int temp;
			 temp=lhs+rhs.x;
			 return temp;
          }
		  void display()
		  {
		     cout<<"x="<<x<<endl;
		  }
};


int main()
{
    Point p(10);
	p.display();
	int i=200;
	int z=i+p;// same as calling Operator+(i,p)
	cout<<"z="<<z<<endl;
	return 0;
}