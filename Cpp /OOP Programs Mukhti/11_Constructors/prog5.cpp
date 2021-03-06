#include<iostream>
using namespace std;

class A
{
   int x;
   public:
        A(int i);
		~A();
		void display();
};

A::A(int i)
{
   x=i;
}

A::~A()
{
   cout<<"Object is destroyed"<<endl;
}

void A::display()
{
   cout<<"The value of x="<<x<<endl;
}

int main()
{
   A ob1=100;
   ob1.display();
   return 0;
}