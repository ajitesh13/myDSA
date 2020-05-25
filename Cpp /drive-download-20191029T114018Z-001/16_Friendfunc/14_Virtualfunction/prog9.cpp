/* Calculating volume of a sphere and a cube by implementing
dynamic polymorphism */
#include<iostream>
using namespace std;
const double PI=3.14;

class Container
{
   protected:
   double x;
   public:
         virtual void init()=0;
         virtual void volume()=0;
};

class Cube:public Container
{
   public:
         void init()
		 {
		   cout<<"Enter length of the side of the cube"<<endl;
		   cin>>x;
		 }
         void volume()
         {
            cout<<"Volume of the cube is="<<x*x*x<<endl;
         }			
};

class Sphere:public Container
{
   public:
         void init()
		 {
		   cout<<"Enter length of the radius of the sphere"<<endl;
		   cin>>x;
		 }
         void volume()
         {
            cout<<"Volume of the sphere is="<<((double)4/3)*PI*x*x*x<<endl;
         }			
};

int main()
{
   Container *c;
   Cube cb;
   c=&cb;
   c->init();
   c->volume();
   Sphere s;
   c=&s;
   c->init();
   c->volume();
   return 0;
}