#include<iostream>
using namespace std;

class Point
{
      int y;
   public:
        int x;
		void show(){cout<<"y="<<y<<endl;}
};

int main()
{
   int *p;
   Point pob;
   p=&pob.x;
   *p=100;
   cout<<pob.x<<endl;
   *p--;
   *p=200;
   pob.show();
   return 0;
}