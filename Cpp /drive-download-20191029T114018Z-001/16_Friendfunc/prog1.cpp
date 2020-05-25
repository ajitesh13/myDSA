/* Friend functions are non-member functions.
Hence, they don't have this pointer.
Friend functions can access all the members of 
a class to which they are friends. As they are not
having this pointer, they cannot access class members
directly. Rather, they access class members through an
object of the respective class to which they are friends.
A non-member function can be made a friend function
of a class by preceding that function's declaration
with a friend keyword. */

#include<iostream>
using namespace std;

class Myclass
{
   int x;
   public:
         Myclass(int i)
		 {x=i;}
		 friend void myfriend(Myclass ob);
		 //friend void myfriend();
};

void myfriend(Myclass ob)
{
    cout<<"Square of x="<<ob.x*ob.x<<endl;
}

/*void myfriend()
{
    cout<<"Square of x="<<x*x<<endl;
}*/

int main()
{
   Myclass temp(10);
   myfriend(temp);
   return 0;
}