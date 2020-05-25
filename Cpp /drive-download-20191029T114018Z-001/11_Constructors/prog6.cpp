#include<iostream>
using namespace std;

class Figure
{
   double l,b;
   public:
        A(double s);
		A(double x,double y);
		~A();
		double area();
};

Figure::Figure(double s)
{
   l=s;
   cout<<"Area of the square="<<l*l<<endl;
}

Figure::Figure(double x,double y)
{
   l=x;
   b=y;
   cout<<"Area of the rectangle="<<l*b<<endl;
}

Figure::~Figure()
{
   cout<<"Object is destroyed"<<endl;
}

int main()
{
   A square(2.5), rectangle(1.5,3.5);
   return 0;
}