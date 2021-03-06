#include<iostream>
using namespace std;
int main()
{
   cout<<"Hello"<<endl;
   int x(2000);//implicit initilization
   cout<<"the value of x="<<x<<endl;
   cout<<"Enter a value for x"<<endl;
   cin>>x;
   cout<<"x="<<x<<endl;
   x=1000;//explicit initialization
   cout<<"the value of x="<<x<<endl;
   
   return 0;
}

int printf(const char*, ...);