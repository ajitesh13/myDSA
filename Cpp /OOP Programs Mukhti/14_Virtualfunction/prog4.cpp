/* Virtual functions */
#include<iostream>
using namespace std;

class Base
{
   public:
         int x;
		 virtual void show(){x=100;cout<<"x in base = "<<x<<endl;}
};

class Derived:public Base
{
   public:
         int y;
		 void show()
		 {
		   x=200;
			y=400;
			cout<<"x in derived = "<<x<<endl;
			cout<<"y in derived = "<<y<<endl;
		 }
};

int main()
{
   Base b, *bptr;
   bptr=&b;
   bptr->show();//Will call the show() from Base
   Derived d;
   bptr=&d;
   bptr->show();//Will call the show() from Derived
   return 0;
}