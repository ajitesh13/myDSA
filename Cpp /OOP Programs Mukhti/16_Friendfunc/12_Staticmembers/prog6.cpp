/* One of the applications of static attributes of a class are 
   to count the number of objects created for that class automatically. */

#include<iostream>
using namespace std;

class Myclass
{
    static int counter;
	public:
	    Myclass()
		{
		    counter++;
			cout<<"Number of objects created are="<<counter<<endl;
		}
};

int Myclass::counter;

void nonmemberfunction(){Myclass ob4;}

int main()
{
   Myclass ob1,ob2,ob3;
   nonmemberfunction();
   return 0;
}