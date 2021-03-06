/* Passing parameters to base class constructors */
#include<iostream>
using namespace std;

class Base
{
   public:
        int x;
		Base(){}
        Base(int i){x=i;}
};

class Derived:public Base
{
   public:
        int y;
		Derived(){y=101;}
		Derived(int a):Base(a)
		{y=200;}
};

int main()
{
   Base(20);
   Base b;
   Base a(40);
   Derived D;
   cout<<"x in Derived="<<b.x<<endl;
   cout<<"x in Derived="<<a.x<<endl;
   cout<<"x in Derived="<<D.x<<endl;
   return 0;
}