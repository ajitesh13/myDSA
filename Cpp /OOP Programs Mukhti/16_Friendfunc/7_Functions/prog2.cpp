#include<iostream>
using namespace std;

void f(int x);//void functions cannot return any value

int main()
{
   int i=20;
   cout<<"i square="<<f(i)<<endl;// i is the actual parameter
   return 0;
}

void f(int x)
{
  return x*x;
}