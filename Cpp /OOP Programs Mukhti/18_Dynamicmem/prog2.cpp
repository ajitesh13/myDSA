#include<iostream>
using namespace std;

int main()
{
   int *p;
   p=new int[5];
   for(int i=0;i<5;i++)
   {
      cout<<"Enter an integer"<<endl;
      cin>>p[i];
   }
   for(int j=0;j<5;j++)
   {
     cout<<"The value is:"<<p[j]<<endl;
   }
   delete []p;
   return 0;
}