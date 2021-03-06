/* Overloading by changing the ordering of
parameters */

#include<iostream>
using namespace std;

void f(int i, char c);
void f(char c, int i);

int main()
{
   f(100,'B');
   f('Z',200);
   return 0;
}

void f(int i, char c)
{cout<<"i="<<i<<endl;
 cout<<"c="<<c<<endl;}

void f(char c, int i)
{cout<<"c="<<c<<endl;
 cout<<"i="<<i<<endl;}