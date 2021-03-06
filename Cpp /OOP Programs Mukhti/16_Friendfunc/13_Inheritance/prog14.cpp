/* Solution to diamond inheritance problem through scope resolution operator */
#include<iostream>
using namespace std;

class Base
{
   public:
        int x;
};

class Derived1:public Base
{};

class Derived2:public Base
{};

class Derived3:public Derived1, public Derived2
{};

int main()
{
   Derived3 D3;
   D3.Derived1::x=10;
   D3.Derived2::x=20;
   cout<<"x from Derived1 ="<<D3.Derived1::x<<endl;
   cout<<"x from Derived2 ="<<D3.Derived2::x<<endl;
   return 0;
}