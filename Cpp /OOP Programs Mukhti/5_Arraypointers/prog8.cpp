#include<iostream>
using namespace std;
int main()
{
   int x=10;
   int *const p=&x;
   cout<<*p<<endl;
   *p=100;
   cout<<*p<<endl;
   int y=20;
   p=&y;//Will generate error
   cout<<*p<<endl;
   return 0;
}