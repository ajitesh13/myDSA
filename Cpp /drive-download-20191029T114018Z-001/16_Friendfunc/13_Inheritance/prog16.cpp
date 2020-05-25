/* Order of execution of constructors and destructors*/
#include<iostream>
using namespace std;

class Base
{
   public:
        Base(){cout<<"Base is created"<<endl;}
		~Base(){cout<<"Base is destroyed"<<endl;}
};

class Derived1:Base
{
   public:
        Derived1(){cout<<"Derived1 is created"<<endl;}
		~Derived1(){cout<<"Derived1 is destroyed"<<endl;}
};

class Derived2:Derived1
{
   public:
        Derived2(){cout<<"Derived2 is created"<<endl;}
		~Derived2(){cout<<"Derived2 is destroyed"<<endl;}
};

int main()
{
   Derived2 D2;
   return 0;
}