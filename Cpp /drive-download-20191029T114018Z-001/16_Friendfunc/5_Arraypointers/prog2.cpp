#include<iostream>
using namespace std;
int main()
{
   int const size=5;
   int expr;
   double value[size]={3.0,4.0,6.0,8.0,10.0};
   expr=1|2|3|4;
   cout<<value[expr]<<endl;
   return 0;
}