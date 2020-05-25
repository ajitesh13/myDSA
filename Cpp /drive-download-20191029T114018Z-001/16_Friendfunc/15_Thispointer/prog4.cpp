#include<iostream>
using namespace std;

/*int f(int a)
{
   int *p=&a;
   return *p;//returns a value
}*/

/*int* f(int a)
{
   int *p=&a;
   return p;// returns an address and a pointer is pointing to that address
}*/

int& f(int a)
{
   int *p=&a;
   return *p;
}

int main()
{
   int x=100;
   cout<<f(x)<<endl;
   return 0;
}