#include<iostream>
using namespace std;

class Base
{
   public:
        int x;
};

class Derived:private Base
{
   public:
        int y;
};

int main()
{
   Derived d;
   d.x=10;//Will generate error as x is private
   d.y=20;
   cout<<"Sum="<<d.x+d.y<<endl;
   return 0;
}