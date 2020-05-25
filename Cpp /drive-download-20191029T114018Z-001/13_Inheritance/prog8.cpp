#include<iostream>
using namespace std;

class Base
{
   public:
        int x;
};

class Derived:Base //By default inheritance will be private
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