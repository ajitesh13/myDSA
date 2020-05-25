#include<iostream>
using namespace std;

int f(int x);
int f(int x,int y=10);

int main()
{
   cout<<"Result="<<f(5)<<endl;
   cout<<"Another result="<<f(10,100);
   return 0;
}

int f(int x,int y)
{return x+y;}

int f(int x)
{return x*x;}