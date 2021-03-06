#include<iostream>
using namespace std;

void f(double d);
void f(float f);

int main()
{
   f(10);
   f(20.5);
   return 0;
}

void f(double d)
{cout<<"d="<<d<<endl;}

void f(float f)
{cout<<"f="<<f<<endl;}