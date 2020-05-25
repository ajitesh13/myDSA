#include<iostream>
using namespace std;

class Complex
{
   int real;
   int img;
   public:
       Complex(){}
	   Complex(int a,int b){real=a;img=b;}
	   Complex operator*(Complex rhs)
	   {
	      real=real*rhs.real-img*rhs.img;
		  img=img*rhs.real+real*rhs.img;
	   }
	   void show()
	   {
	      cout<<"real="<<real<<endl;
		  cout<<"img="<<img<<endl;
	   }
};

int main()
{
   Complex c1(1,2), c2(4,5);
   Complex c3;
   c3=c1*c3;
   c3.show();
   return 0;
}