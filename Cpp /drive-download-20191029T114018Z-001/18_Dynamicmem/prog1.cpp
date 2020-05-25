/* Dynamic memory management with new and delete */

#include<iostream>
using namespace std;

int main()
{
   int *p;
   p=new int;
   cout<<"Enter an integer"<<endl;
   cin>>*p;
   cout<<"The value is:"<<*p<<endl;
   delete p;
   return 0;
}



