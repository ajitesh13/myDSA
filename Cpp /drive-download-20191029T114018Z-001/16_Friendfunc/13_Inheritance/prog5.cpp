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
		void show();
};

void Derived::show()
{
    x=10;
	y=20;
	cout<<"Sum="<<x+y<<endl;
}

int main()
{
   Derived d;
   d.show();
   return 0;
}