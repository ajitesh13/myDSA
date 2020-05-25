/* Another application to keep track of order of
   execution of constructor and destructor for a class. */

#include<iostream>
using namespace std;

class Myclass
{
    static int counter;
	public:
	    Myclass()
		{
		    counter++;
			cout<<" Object number "<<counter<<" is created"<<endl;
		}
		~Myclass()
		{   
		    cout<<" Object number "<<counter<<" is destroyed"<<endl;
            counter--;
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