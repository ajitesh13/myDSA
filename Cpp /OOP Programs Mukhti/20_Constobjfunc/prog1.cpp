/* const member function */

#include<iostream>
using namespace std;

class Point
{
   int i;
   public:
        int geti() const
		{ return i; }
		/*void seti(int x) const
		{ i=x; }*/
};

int main()
{
   Point p;
   //p.seti(90);// error as seti() is trying to modify the value of i
   cout<<p.geti()<<endl;
   return 0;
}