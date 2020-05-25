/* A static member function if placed under public visibility,
   then that can be accessed directly by a class using scope
   resolution operator. We don't require an object of the class
   to access that object. */

#include<iostream>
using namespace std;

class Myclass
{
    static int si;
	public:
	    static void sf()
		{
		    si=20;
			cout<<"Accessing static si in static sf="<<si<<endl;
			si++;
		}
};

int Myclass::si;

int main()
{
   Myclass::sf();
   cout<<"Through class name"<<endl;
   Myclass ob;
   ob.sf();
   cout<<"Through object"<<endl;
   return 0;
}