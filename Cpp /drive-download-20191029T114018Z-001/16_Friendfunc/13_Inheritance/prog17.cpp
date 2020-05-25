/* Passing parameters to base class constructors */
#include<iostream>
using namespace std;

class Base
{
   public:
        int x;
		//solution 1 by providing a default base constructor
		Base(){}
        Base(int i){x=i;}
};

class Derived:public Base
{
   public:
        int y;
		Derived(){x=100; y=200;}
};

int main()
{
   Derived D;
   cout<<"x in Derived="<<D.x<<endl;
   cout<<"y in Derived="<<D.y<<endl;
   return 0;
}