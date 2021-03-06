/* Passing parameters to multiple base class constructors */
#include<iostream>
using namespace std;

class Base1
{
   public:
        int x;
		    Base1(int ){x=i;}
};

class Base2
{
   public:
        int p,q;
		    Base2(int i,int j){p=i; q=j;}
};
class Derived:public Base1,public Base2
{
   public:
        // solution 2 by passing parameters to base constructors
        Derived(int a,int b):Base1(a),Base2(a,b)
		{x=a; p=a; q=b;}
};

int main()
{
   Derived D(20,40);
   cout<<"x in Derived="<<D.x<<endl;
   cout<<"p in Derived="<<D.p<<endl;
   cout<<"q in Derived="<<D.q<<endl;
   return 0;
}