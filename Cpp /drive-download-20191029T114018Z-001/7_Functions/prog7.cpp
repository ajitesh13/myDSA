#include<iostream>
using namespace std;

int f(int x,int y=3,int z);//Will generate an error
/* Default parameter values are assigned from
right to left continuously. */
int main()
{
   int i=20,j=40, k=60;
   cout<<"Sum="<<f(i,j,k)<<endl;
   cout<<"Sum="<<f(i,j)<<endl;
   return 0;
}

int f(int x,int y,int z)
{
  return x+y+z;
}