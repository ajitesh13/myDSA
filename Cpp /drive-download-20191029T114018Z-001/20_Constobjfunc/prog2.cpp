/* mutable attributes */

/* 
Sometimes we may want that one or more
members of a class can be modified, even
if we declare a const member function. And 
other members cannot be modified through a 
const member function. This constness can
be overriden by declaring an attribute as 
mutable
*/

#include<iostream>
using namespace std;

class Point
{
   mutable int i;
   int j;
   public:
        int geti() const
		{ return i; }
		void seti(int x) const
		{ i=x; }
};

int main()
{
   Point p;
   p.seti(90);// as i is set as mutable, seti() can change i's value
   cout<<p.geti()<<endl;
   return 0;
}