#include<iostream>
using namespace std;
int main()
{
   int x=10;
   const int *const p=&x;
   cout<<*p<<endl;
   *p=100;//Will generate an error
   cout<<*p<<endl;
   int y=20;
   p=&y;//Will generate an error
   cout<<*p<<endl;
   return 0;
}