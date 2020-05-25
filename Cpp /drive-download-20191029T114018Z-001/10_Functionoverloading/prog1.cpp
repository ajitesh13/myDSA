/* Overloading by changing the type of
parameters */

#include<iostream>
using namespace std;

void f(int i);
void f(char c);

int main()
{
   f(10);
   f('A');
   return 0;
}

void f(int i)
{cout<<"i="<<i<<endl;}

void f(char c)
{cout<<"c="<<c<<endl;}