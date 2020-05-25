/* Static attributes are created prior to the creation of any object of a class.
   Thus, static attributes, if placed under public visibilty, can be accessed by
   a class name using a scope resolution operator. */
   
#include<iostream>
using namespace std;

class Myclass
{
   public:
        static int si;
};

int Myclass::si;

int main()
{
   cout<<"Accessing si using class name"<<endl;
   Myclass::si=10;
   cout<<"si="<<Myclass::si<<endl;
   Myclass ob;
   cout<<"Accessing si using object name"<<endl;
   cout<<"si for ob is="<<ob.si<<endl;
   Myclass::si++;
   cout<<"Updated si for ob is="<<ob.si<<endl;
   return 0;
}