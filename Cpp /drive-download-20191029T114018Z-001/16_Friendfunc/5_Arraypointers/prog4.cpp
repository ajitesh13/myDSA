#include<iostream>
using namespace std;
int main()
{
   int *i;
   char *c;
   double *d;
   cout<<sizeof(i)<<endl;
   cout<<sizeof(c)<<endl;
   cout<<sizeof(d)<<endl;
   cout<<sizeof(*i)<<endl;
   cout<<sizeof(*c)<<endl;
   cout<<sizeof(*d)<<endl;
   
   return 0;
}