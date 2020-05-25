/* A user defined function can also 
   contain an entire exception 
   handling routine.  */
   
#include<iostream>
using namespace std;
void f()
{
   cout<<"Inside a user defined function"<<endl;
   try{
        cout<<"Inside try block"<<endl;
        throw "hello";
	  }
   catch(const char *cp)
   {
        cout<<"Caught a string= "<<cp<<endl;
   }
}
int main()
{
   cout<<"Entry"<<endl;
   f();
   cout<<"End"<<endl;
   
   return 0;
}

