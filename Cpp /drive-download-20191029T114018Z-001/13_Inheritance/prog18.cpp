/* Passing parameters to base class constructors */
#include<iostream>
using namespace std;

class Base
{
   public:
        int x;
		    Base(int i){x=i;}
};

class Derived:public Base
{
   public:
        // solution 2 by passing parameters to base constructors
        Derived(int j):Base(j)
		{x=j;}
};

int main()
{
   Derived D(20);
   cout<<"x in Derived="<<D.x<<endl;
   return 0;
}