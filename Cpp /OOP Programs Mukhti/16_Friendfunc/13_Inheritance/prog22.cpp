#include<iostream>
using namespace std;

class Base
{
   public:
        void show(){cout<<"I am from Base"<<endl;}
};

class Derived1:virtual public Base
{};

class Derived2:virtual public Base
{};
   
class Derived3:public Derived1, public Derived2
{public:
      /*void show(){cout<<"I am from derived 3"<<endl;}*/
};

int main()
{
   Derived3 d3;
   d3.show();
   return 0;
}