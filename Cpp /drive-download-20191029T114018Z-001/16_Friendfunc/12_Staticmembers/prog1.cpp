/* Static attributes are by default initialized to zero
   and only one copy is available for all the objects of
   a class unlike normal attributes of a class for which 
   individual copies are available per object. */
#include<iostream>
using namespace std;

class Myclass
{
   public:
        int i;
		static int si; // Only declaration has been made. No storage is allocated.
};

int Myclass::si;// Defined and storage is allocated.

int main()
{
    Myclass ob1,ob2;
	cout<<"i in ob1="<<ob1.i<<endl;
	cout<<"si in ob1="<<ob1.si<<endl;
	cout<<"i in ob2="<<ob2.i<<endl;
	cout<<"si in ob2="<<ob2.si<<endl;
	cout<<"___________________________"<<endl;
	
	ob1.i=10;
	ob1.i++;
	cout<<"i in ob1="<<ob1.i<<endl;
	cout<<"i in ob2="<<ob2.i<<endl;
	cout<<"___________________________"<<endl;
	
	ob1.si++;
	cout<<"si in ob1="<<ob1.si<<endl;
	cout<<"si in ob2="<<ob2.si<<endl;
	
	return 0;
}