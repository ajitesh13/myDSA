/*A reference acts as a constant pointer.
Thus, address of a reference cannot be changed. */
#include<iostream>
using namespace std;
int main()
{
   int x=10;
   int &r=x;
   cout<<"x="<<x<<endl;
   cout<<"r="<<r<<endl;
   int y=20;
   r=&y;//Will generate error
   cout<<"y="<<y<<endl;
   cout<<"r="<<r<<endl;
   return 0;
}