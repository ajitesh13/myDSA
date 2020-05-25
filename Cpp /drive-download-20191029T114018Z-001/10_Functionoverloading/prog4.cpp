#include<iostream>
using namespace std;

class Figure
{
   double l, b;
   public:
        double area(double x,double y);
		double area(double x);
};

double Figure::area(double x,double y)
{return x*y;}

double Figure::area(double x)
{return x*x;}

int main()
{
   Figure square, rectangle;
   cout<<"Area of a square="<<square.area(20.2)<<endl;
   cout<<"Area of a rectangle="<<rectangle.area(10.5,20.5)<<endl;
   return 0;
}   