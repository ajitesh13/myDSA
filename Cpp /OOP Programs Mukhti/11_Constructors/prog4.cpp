#include<iostream>
using namespace std;

class A
{
   int x,y;
   public:
        A(int i);
		A(int i,int j);
		~A();
		void display();
};

A::A(int i,int j)
{
   x=i;
   y=j;
}

A::~A()
{
   cout<<"Object is destroyed"<<endl;
}

void A::display()
{
   cout<<"The value of x="<<x<<endl;
   cout<<"The value of y="<<y<<endl;
}

int main()
{
   A ob1(100);
   A ob2(10,20);
   A ob3;
   ob1.display();
   ob2.display();
   ob3.display();
   return 0;
}