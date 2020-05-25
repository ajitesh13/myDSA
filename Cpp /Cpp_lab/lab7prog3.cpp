// 3. With a suitable example explain how ordering of catch blocks plays an 
//    important role while dealing with exceptions of both base type and derived type. 



#include<iostream>
using namespace std;

class Base
{};
class Derived:public Base
{};

int main()
{
   Base b;
   Derived d;
   try
   {
      cout<<"Inside try"<<endl;
	  throw d;
   }
    
   catch(Derived tempd)
   {
      cout<<"Caught a derived"<<endl;
   } 
   catch(Base tempb)
   {
      cout<<"Caught a base"<<endl;
   }
   
   cout<<"End"<<endl;
   
   return 0;
}
