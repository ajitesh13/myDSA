#include<iostream>
using namespace std;

class A
{
   public:
   int x;      
};

void myfriend(A aob)
{
   aob.x=10;
   cout<<"x="<<aob.x<<endl;
}

int main()
{
   A atemp;
   myfriend(atemp);
   return 0;
}