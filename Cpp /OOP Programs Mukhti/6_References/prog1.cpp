/*A reference is another name for an 
existing varibale or it is an alias
of an existing variable. If we will
modify the actual variable then the
modification will be reflected on the
reference variable too. The vice-versa 
is also true. */
#include<iostream>
using namespace std;
int main()
{
   int x=10;
   int &r=x;
   cout<<"x="<<x<<endl;
   cout<<"r="<<r<<endl;
   r++;
   cout<<"r="<<r<<endl;
   cout<<"x="<<x<<endl;
   x--;
   cout<<"x="<<x<<endl;
   cout<<"r="<<r<<endl;
   return 0;
}