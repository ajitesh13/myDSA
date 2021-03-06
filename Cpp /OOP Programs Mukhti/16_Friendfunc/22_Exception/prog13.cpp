#include<iostream>
using namespace std;

int main()
{
   int a,b;
   try
   {
      cout<<"Enter the numerator"<<endl;
	  cin>>a;
	  cout<<"Enter the denominator"<<endl;
	  cin>>b;
	  if(b==0)
	      throw b;
	  else
	      cout<<"The result is = "<<a/b<<endl;
   }
   catch(int i)
   {
      cout<<"Division by zero is not possible"<<endl;
	  cout<<"You have entered denominator = "<<i<<endl;
   }
        
   cout<<"End"<<endl;
   
   return 0;
}