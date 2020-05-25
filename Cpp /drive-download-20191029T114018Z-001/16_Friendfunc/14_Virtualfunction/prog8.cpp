/* Pure virtual functions in multilevel inheritance */
#include<iostream>
using namespace std;

class Base
{
   public:
         int x;
		 virtual void show()=0;
};

class Derived:public Base
{
   public:
         int y;
		 /*void show()
		 {
		    x=200;
			y=400;
			cout<<"x in derived = "<<x<<endl;
			cout<<"y in derived = "<<y<<endl;
			cout<<"\n";
		 }*/
};

int main()
{
   //Base b, *bptr;
   //bptr=&b;
   //bptr->show();
   Base *bptr;
   Derived d;
   bptr=&d;
   bptr->show();
   return 0;
}