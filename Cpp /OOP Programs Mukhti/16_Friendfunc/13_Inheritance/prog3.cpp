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
		void show();
};

void Derived::show()
{
   x=10;// Will generate error as x is not accessible here
   y=20;
   cout<<"x="<<x<<endl;
   cout<<"y="<<y<<endl;
}

int main()
{
   Derived d;
   d.show();
   return 0;
}