/* Base type poniters when assigned with 
   the addresses of derived type objects
   can only point to those attributes 
   which are inherited from base to derive.*/
#include<iostream>
using namespace std;

class Base
{
   public:
         int x;
};

class Derived:public Base
{
   public:
         int y;
};

int main()
{
   Base b, *bptr;
   bptr=&b;
   bptr->x=100;
   cout<<"x in base ="<<bptr->x<<endl;
   Derived d;
   bptr=&d;
   bptr->x=200;
   bptr->y=400;//Will generate an error
   cout<<"x in derived ="<<bptr->x<<endl;
   cout<<"y in derived ="<<bptr->y<<endl;//Will generate an error
   return 0;
}