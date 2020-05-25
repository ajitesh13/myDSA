#include<iostream>
using namespace std;

void f(int i);
void f(int &r);

int main()
{
   int x=20;
   f(x);
   f(x);
   return 0;
}

void f(int i)
{cout<<"i="<<i<<endl;}

void f(int &r)
{cout<<"r="<<r<<endl;}