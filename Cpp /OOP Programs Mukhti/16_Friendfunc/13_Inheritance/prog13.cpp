/* Diamond inheritance problem */
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
   D3.x=10;//x is ambigous as multiple copies are available
   cout<<"x="<<D3.x<<endl;
   return 0;
}