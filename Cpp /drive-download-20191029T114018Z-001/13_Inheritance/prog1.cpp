/* Single level inheritance */
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
   Derived d;
   d.x=10;
   d.y=20;
   cout<<"Sum="<<d.x+d.y<<endl;
   return 0;
}