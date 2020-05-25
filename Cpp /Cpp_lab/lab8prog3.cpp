// 3.       Write a program to overload a generic 
//          function along with specific version of the 
//          same function.


#include<iostream>
using namespace std;

template<class T> void myswap(T &a, T &b)
{
   cout<<"Generic function is called"<<endl;
   T temp;
   temp=a;
   a=b;
   b=temp;
}

void myswap(int &a,int &b)
{
   cout<<"Specific function is called"<<endl;
   int temp;
   temp=a;
   a=b;
   b=temp;
}

int main()
{
   int i1=10, i2=20;
   double d1=11.5, d2=13.4;
   char c1='H', c2='Y';
   
   cout<<"Before swapping"<<endl;
   cout<<"____________________________"<<endl;
   cout<<"i1="<<i1<<" i2="<<i2<<endl;
   cout<<"d1="<<d1<<" d2="<<d2<<endl;
   cout<<"c1="<<c1<<" c2="<<c2<<endl;
   
   myswap(i1,i2); // myswap(int,int) is called
   myswap(d1,d2); // myswap(T,T) will be called
   myswap(c1,c2); // myswap(T,T) will be called
      
   cout<<"After swapping"<<endl;
   cout<<"____________________________"<<endl;
   cout<<"i1="<<i1<<" i2="<<i2<<endl;
   cout<<"d1="<<d1<<" d2="<<d2<<endl;
   cout<<"c1="<<c1<<" c2="<<c2<<endl;
   
   return 0;
}