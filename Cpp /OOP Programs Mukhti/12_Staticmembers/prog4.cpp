/* There cannot be static and non-static version of the same function
   in a same class. */

#include<iostream>
using namespace std;

class Myclass
{
    static int si;
	public:
	    static void sf(int k)
		{
		    si=k;
			cout<<"Accessing static si in static sf="<<si<<endl;
		}
		void sf()
		{
		    si=30;
			cout<<"Accessing static si in nonstatic sf="<<si<<endl;
		}
};

int Myclass::si;

int main()
{
   Myclass ob;
   ob.sf(20);
   return 0;
}