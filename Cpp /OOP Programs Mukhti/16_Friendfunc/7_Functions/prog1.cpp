#include<iostream>
using namespace std;

int f(int x);//Function declaration having x as formal parameter

int main()
{
   int i=20;
   cout<<"i square="<<f(i)<<endl;// i is the actual parameter
   return 0;
}

int f(int x)
{
  return x*x;
}