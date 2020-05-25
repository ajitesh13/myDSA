#include<iostream>
using namespace std;

class Point
{
   int x;
   public:
         void get()
		 {cout<<"Enter a value for x"<<endl;
		  cin>>x;}
		 void show()
		 {cout<<"x="<<x<<endl;}
};
		 
int main()
{
   Point *p;
   p=new Point;
   p->get();
   p->show();
   delete p;
   return 0;
}