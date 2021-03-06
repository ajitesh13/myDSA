/* A generic catch block can 
   catch any type of exception. */
   
#include<iostream>
using namespace std;
void f(int k)
{
   cout<<"Inside a user defined function"<<endl;
   if(k==0)
      throw 100;
   else if(k==1)
      throw 20.5;
   else if(k==2)
      throw 'M';
   else  
      throw "Hello";
   
}
int main()
{
   cout<<"Entry"<<endl;
   cout<<"Enter an integer"<<endl;
   int i;
   cin>>i;
   try
   {
      f(i);
   }
   catch(...){cout<<"Caught an exception"<<endl;}
     
   cout<<"End"<<endl;
   
   return 0;
}
