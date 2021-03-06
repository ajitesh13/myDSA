/* The using keyword */


#include<iostream>
#include "newadd.h"
#include "newsub.h"
using namespace std;

int main()
{
   using namespace A;
   cout<<"Addition result="<<calculate(10,20)<<endl;
   cout<<"Subtraction result="<<B::calculate(10,20)<<endl;
   return 0;
}