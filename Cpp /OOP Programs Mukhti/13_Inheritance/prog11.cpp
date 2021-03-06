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

class Derived2:public Derived1 
{
   public:
        int z;
};

int main()
{
   Derived2 d2;
   d2.x=30;
   d2.y=50;
   d2.z=40;
   cout<<"Sum="<<d2.x+d2.y+d2.z<<endl;
   return 0;
}