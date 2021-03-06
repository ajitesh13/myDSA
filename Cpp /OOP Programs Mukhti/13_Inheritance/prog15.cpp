/* Solution to diamond inheritance problem through virtual base class */
#include<iostream>
using namespace std;

class Base
{
   public:
        int x;
};

class Derived1:public virtual Base
{};

class Derived2:public virtual Base
{};

class Derived3:public Derived1, public Derived2
{};

int main()
{
   Derived3 D3;
   D3.x=10;
   cout<<"x = "<<D3.x<<endl;
   return 0;
}