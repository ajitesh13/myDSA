/*Unlike a pointer, a reference must
be initialized upon declaration. */
#include<iostream>
using namespace std;
int main()
{
   int x=10;
   int *p;
   p=&x;
   cout<<*p<<endl;
   int &r;// Error
   r=x;
   cout<<"x="<<x<<endl;
   cout<<"r="<<r<<endl;
   return 0;
}