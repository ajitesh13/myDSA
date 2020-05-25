#include<iostream>
using namespace std;

inline int getbigger(int,int);

int main()
{
   int x,y;
   cout<<"Enter first integer"<<endl;
   cin>>x;
   cout<<"Enter second integer"<<endl;
   cin>>y;
   cout<<"Bigger between the two is="<<getbigger(x,y)<<endl;
   return 0;
}

int getbigger(int a,int b)
{
   return (a>=b?a:b);
}