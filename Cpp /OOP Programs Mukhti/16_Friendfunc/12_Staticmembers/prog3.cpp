/* Static member functions may only directly refer to
   other static members of the class.
   A static member function does not have a this pointer. */
   
#include<iostream>
using namespace std;

class Myclass
{
    int i;
	static int si;
	public:
	    static void sf()
		{
		    //i=10;
			si=20;
			//cout<<"Accessing non-static i="<<i<<endl;
			cout<<"Accessing static si="<<si<<endl;
		}
};

int Myclass::si;

int main()
{
   Myclass ob;
   ob.sf();
   return 0;
}