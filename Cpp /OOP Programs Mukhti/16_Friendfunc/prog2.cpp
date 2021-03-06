/* A friend class can access all the members of another class
to which it is friend. A friend class can be created by preceding
the class' declaration with a friend keyword. */

#include<iostream>
using namespace std;

class A
{
   int x;
   public:
        friend class B;
};

class B
{
   public:
       void display(A aob)
	   {
	      aob.x=100;
		  cout<<"Sum of two x is:"<<aob.x+aob.x<<endl;
	   }
};

int main()
{
   A atemp;
   B btemp;
   btemp.display(atemp);
   return 0;
}