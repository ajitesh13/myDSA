/* Pointer to a function */

#include<iostream>
using namespace std;

int a(int,int);
int s(int,int);
int m(int,int);
int d(int,int);

int main()
{
   int v1,v2;
   cout<<"Enter two integer values"<<endl;
   cin>>v1>>v2;
   
   cout<<"1. To add"<<endl;
   cout<<"2. To subtract"<<endl;
   cout<<"3. To multiply"<<endl;
   cout<<"4. To divide"<<endl;
   
   int choice;
   cout<<"Please enter your choice"<<endl;
   cin>>choice;
   
   int (*fp[4])(int,int)={a,s,m,d};
   
   cout<<"Result = "<<(*fp[choice-1])(v1,v2)<<endl;
   return 0;
}

int a(int x,int y)
{ return (x+y); }

int s(int x,int y)
{ return (x-y); }

int m(int x,int y)
{ return (x*y); }

int d(int x,int y)
{ return (x/y); }