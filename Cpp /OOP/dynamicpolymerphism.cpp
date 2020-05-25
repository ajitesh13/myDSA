#include <iostream>
using namespace std;

class Base{
   public:
      int x;
      virtual void show(){
         x = 100;
         cout<<"x = "<<x<<endl;
      }
};

class Derived:public Base{
   public:
      int y;
      void show(){
         x = 200;
         y = 400;
         cout<<"x = "<<x<<endl;
         cout<<"y = "<<y<<endl;
      }
};

void display(Base &ref){
   ref.show();
}

int main(){
   Base b;
   display(b);
   Derived d;
   display(d);
   return 0;
}