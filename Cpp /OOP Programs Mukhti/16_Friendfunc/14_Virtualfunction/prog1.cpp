#include <iostream>
using namespace std;

class A{
   public:
      int x;
      int y;
      A(){}
      A(int a, int b){x = a; y = b;}
      void show(){
         cout << x << " " << y << endl;
      }
};

class B:public A{
   public:
      int z;
};

int main(){
   A ob, *ptr;
   B devob;
   ptr = &devob;
   cout << ptr->

}