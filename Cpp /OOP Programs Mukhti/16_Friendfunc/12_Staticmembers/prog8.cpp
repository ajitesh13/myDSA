#include<iostream>
using namespace std;

class A
{
   int x;
   A(int i){x=i;}
   public:
      static void sf();
	  void display();
};

void A::sf()
{
   A ob(20);
   ob.display();
}

void A::display()
{
   cout<<"x="<<x<<endl;
}

int main()
{
   //A temp(20);	
   A::sf();
   return 0;
}