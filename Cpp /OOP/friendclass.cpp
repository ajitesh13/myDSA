/*
   Friend class can access all the members of another class to which it is 
   friend
*/
#include <iostream>
using namespace std;

class A{
      int x;
   public:
      friend class B;
      void display(){
         cout<<"Hey! this is a display function in class A"<<endl;
      }
};

class B{
   public:
      void display(A ob){
         ob.x = 200;
         cout<<"The value of x is "<<ob.x<<endl;
      }
      void display_of_A(A ob){
         ob.display();
      }
};

int main(){
   A ob1;
   B ob2;
   ob2.display(ob1);
   ob2.display_of_A(ob1);
   return 0;
}