#include<iostream>
using namespace std;

int f(int a,int b){return a+b;}
void f(int a,int b){cout<<a+b<<endl;}

int main()
{
   cout<<f(100,200)<<endl;
   return 0;
}
    