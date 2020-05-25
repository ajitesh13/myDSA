/* An exception can be thrown from a 
   user defined function. But, the 
   function need to be called from 
   within the try block. */
   
#include<iostream>
using namespace std;
void f()
{
   cout<<"Inside a user defined function"<<endl;
   throw "hello";
}
int main()
{
   cout<<"Entry"<<endl;
   try
   {
       cout<<"Inside try"<<endl;
	   f();
	   cout<<"This statement is not going to execute"<<endl;
   }
   catch(const char *cp)
   {
      cout<<"Caught a string = "<<cp<<endl;
   }   
   cout<<"End"<<endl;
   
   return 0;
}

