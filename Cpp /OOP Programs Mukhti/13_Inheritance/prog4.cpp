#include<iostream>
using namespace std;

class Base
{
   protected:
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
   d.x=10;//Will generate error as x is not accessible directly
   d.y=20;
   cout<<"Sum="<<d.x+d.y<<endl;
   return 0;
}