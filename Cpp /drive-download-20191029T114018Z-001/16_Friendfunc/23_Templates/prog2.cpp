#include<iostream>
using namespace std;

template<class A, class B> void f(A a, B b)
{
   cout<<"a="<<a<<" b="<<b<<endl;
}

int main()
{
   f(10,200.5);
   f('T',"Hello");
   return 0;
}
