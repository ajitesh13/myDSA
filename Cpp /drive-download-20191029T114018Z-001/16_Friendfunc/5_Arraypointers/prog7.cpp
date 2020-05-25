#include<iostream>
using namespace std;
int main()
{
   int x=10;
   const int *p=&x;//same as int const *p
   cout<<*p<<endl;
   //*p=100;//Will generate error
   cout<<*p<<endl;
   int y=20;
   p=&y;
   cout<<*p<<endl;
   return 0;
}