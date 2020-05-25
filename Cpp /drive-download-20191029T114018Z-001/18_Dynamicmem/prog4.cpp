#include<iostream>
using namespace std;

class Point
{
   int x;
   public:
         //Point(int a){x=a;}
		 Point(){cout<<"Enter a value for x"<<endl;
		 cin>>x;}
         void show()
		 {cout<<"x="<<x<<endl;}
};
		 
int main()
{
   Point *p;
   p=new Point[5];
   for(int i=0;i<5;i++)
      p[i].show();
   delete []p;
   return 0;
}