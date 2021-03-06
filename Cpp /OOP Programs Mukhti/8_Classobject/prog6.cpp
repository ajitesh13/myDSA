#include<iostream>
using namespace std;

class Calculator
{
   private:
        double x,y;
   public:
	    void get();
		double add();
		double sub();
		double mul();
		double div();
};

void Calculator::get()
{
   cout<<"Enter first number"<<endl;
   cin>>x;
   cout<<"Enter second number"<<endl;
   cin>>y;
}

double Calculator::add()
{
   return x+y;
}

double Calculator::sub()
{
   return x-y;
}

double Calculator::mul()
{
   return x*y;
}

double Calculator::div()
{
   return x/y;
}



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