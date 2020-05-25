/* Overloading by changing the number of
parameters */

#include<iostream>
using namespace std;

int f(int i);
int f(int i, int j);

int main()
{
   cout<<"Sum="<<f(10,20)<<endl;
   cout<<"Square="<<f(25)<<endl;
   return 0;
}

int f(int i)
{return i*i;}

int f(int i, int j)
{return i+j;}