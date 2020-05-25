#include<iostream>
using namespace std;

class Base
{
   private:
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
   d.x=10;//Will generate an error as private is not accessible here
   d.y=20;
   cout<<"Sum="<<d.x+d.y<<endl;
   return 0;
}