/* Resolving ambiguity between class attribute and
a member function's local parameters by using this pointer */
#include<iostream>
using namespace std;

class Point
{
   int x;
   int y;
   public:
         void get(int x, int y)
		 {
		    this->x=x;//try writing x=x
			this->y=y;//try writing y=y
		 }
		 void display()
		 {
		    cout<<"x="<<x<<endl;
			cout<<"y="<<y<<endl;
		 }
};

int main()
{
   Point p;
   p.get(10,20);
   p.display();
   return 0;
}