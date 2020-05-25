#include<iostream>
using namespace std;

class A
{
   public:
   int x;
   A(int i=10)
   {cout<<"A has been called"<<endl;
    x=i;
	cout<<"x in A="<<x<<endl;
   }
};

class B:public A
{  public:
   /*B(int k){cout<<"B has been called"<<endl;
            x=k;
			cout<<"x in B="<<x<<endl;
		   }*/
};

int main()
{
   B bob;
   return 0;
}