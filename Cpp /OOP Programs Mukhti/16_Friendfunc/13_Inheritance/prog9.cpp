#include<iostream>
using namespace std;

class Base1
{
   public:
        int x;
};

class Base2
{
   public:
        int y;
};

class Derived:public Base1, public Base2 
{
   public:
        int z;
};

int main()
{
   Derived d;
   d.x=10;
   d.y=20;
   d.z=30;
   cout<<"Sum="<<d.x+d.y+d.z<<endl;
   return 0;
}