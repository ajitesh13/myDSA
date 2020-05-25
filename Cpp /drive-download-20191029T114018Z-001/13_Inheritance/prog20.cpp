/* Ambiguity in case of calling the same function in case of 
multiple inheritance */
#include<iostream>
using namespace std;

class Base1
{
   public:
        void show(){cout<<"I am from Base 1"<<endl;}
};

class Base2
{
   public:
        void show(){cout<<"I am from Base 2"<<endl;}
};

class Derived:public Base1, public Base2
{
   public:
        void show()
		{cout<<"I am from Derived"<<endl;}
};

int main()
{
   Base1 b1;
   b1.show();
   Base2 b2;
   b2.show();
   Derived D;
   D.show();
   return 0;
}