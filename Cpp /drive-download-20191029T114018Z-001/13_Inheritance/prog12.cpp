#include<iostream>
using namespace std;

class Base
{
   public:
        int x;
};

class Derived1:public Base
{
   public:
        int y;
};

class Derived2:public Base 
{
   public:
        int z;
};

int main()
{
   Derived1 d1;
   d1.x=30;
   d1.y=50;
   cout<<"Sum="<<d1.x+d1.y<<endl;
   Derived2 d2;
   d2.x=30;
   d2.z=40;
   cout<<"Sum="<<d2.x+d2.z<<endl;
   return 0;
}