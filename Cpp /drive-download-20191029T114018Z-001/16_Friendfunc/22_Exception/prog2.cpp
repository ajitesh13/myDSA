#include<iostream>
using namespace std;

int main()
{
   cout<<"Entry"<<endl;
   try
   {
       cout<<"Inside try"<<endl;
	   cout<<"An exception has been thrown"<<endl;
	   throw  100;
	   cout<<"This statement is not going to execute"<<endl;
   }
   catch(int i)
   {
      cout<<"Caught an int i="<<i<<endl;
   }
   
   cout<<"End"<<endl;
   return 0;
}