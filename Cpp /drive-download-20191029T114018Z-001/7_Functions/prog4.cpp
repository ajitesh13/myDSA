#include<iostream>
using namespace std;

void f(int *x,int *y);

int main()
{
   int i=20,j=40;
   cout<<"Before swapping"<<endl;
   cout<<"i="<<i<<" j="<<j<<endl;
   f(&i,&j);//Function called by passing adress of actual parameters
   cout<<"After swapping"<<endl;
   cout<<"i="<<i<<" j="<<j<<endl;
   return 0;
}

void f(int *x, int *y)
{
  int temp=*x;
  *x=*y;
  *y=temp;
}