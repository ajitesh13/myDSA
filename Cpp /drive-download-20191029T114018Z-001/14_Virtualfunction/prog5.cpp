/* Virtual functions in multilevel inheritance */
#include<iostream>
using namespace std;

class Base
{
   public:
         int x;
		 virtual void show(){x=100;cout<<"x in base = "<<x<<endl;cout<<"\n";}
};

class Derived1:public Base
{
   public:
         int y;
		 void show()
		 {
		    x=200;
			y=400;
			cout<<"x in derived1 = "<<x<<endl;
			cout<<"y in derived1 = "<<y<<endl;
			cout<<"\n";
		 }
};

class Derived2:public Derived1
{
   public:
         int z;
		 void show()
		 {
		    x=3333;
			y=5555;
			z=7777;
			cout<<"x in derived2 = "<<x<<endl;
			cout<<"y in derived2 = "<<y<<endl;
			cout<<"z in derived2 = "<<z<<endl;
			cout<<"\n";
		 }
};

int main()
{
   Base b, *bptr;
   bptr=&b;
   bptr->show();//Will call the show() from Base
   Derived1 d1;
   bptr=&d1;
   bptr->show();//Will call the show() from Derived1
   Derived2 d2;
   bptr=&d2;
   bptr->show();//Will call the show() from Derived2
   return 0;
}