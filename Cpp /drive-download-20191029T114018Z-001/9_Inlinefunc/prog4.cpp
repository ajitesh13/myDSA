#include<iostream>
#define BIG(X,Y) (X>=Y?X:Y)
using namespace std;

inline big(int x,int y)
{ return (x>=y?x:y); }

int main()
{
   //int a=100, b=200;
   cout<<"Bigger is="<<BIG(10.5,23.6)<<endl;
   cout<<"Bigger is="<<big(10.5,23.6)<<endl;
   return 0;
}