#include<iostream>
using namespace std;

class Calculator
{
   private:
        double x,y;
   public:
	    void get()
		{
          cout<<"Enter first number"<<endl;
          cin>>x;
          cout<<"Enter second number"<<endl;
          cin>>y;
        }
		double add()
		{
           return x+y;
        }
		double sub()
		{
           return x-y;
        }
		double mul()
		{
           return x*y;
        }
		double div()
		{
           return x/y;
        }
};

int main()
{
   Calculator c;// same as class Calculator c
   c.get();
   cout<<"Sum="<<c.add()<<endl;
   cout<<"Subtraction="<<c.sub()<<endl;
   cout<<"Product="<<c.mul()<<endl;
   cout<<"Division="<<c.div()<<endl;
   return 0;
}