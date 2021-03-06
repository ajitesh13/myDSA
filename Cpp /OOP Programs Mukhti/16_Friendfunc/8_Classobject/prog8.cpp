#include<iostream>
using namespace std;

class A
{
   int x;
   public:
        void get(int a){x=a;}
		void display(){cout<<"x="<<x<<endl;}
};

int main()
{
   A aob;
   aob.get(10);
   aob.display();
   return 0;
}