#include<iostream>
using namespace std;

class A
{
   int x;
   public:
       A();
		~A();
		void display();
};

A::A()
{
   cout<<"Enter a value for x"<<endl;
   cin>>x;
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
   A ob1,ob2;
   ob1.display();
   ob2.display();
   return 0;
}