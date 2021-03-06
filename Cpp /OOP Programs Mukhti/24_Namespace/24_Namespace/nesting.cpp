/* Nesting of namespaces */

#include<iostream>
using namespace std;

namespace outer
{
   int a;
   
   namespace inner
   {
       int b;
   }
   
}

// int main()
// {
//    outer::a=100;
//    outer::inner::b=200;
//    cout<<"Sum="<<outer::a + outer::inner::b<<endl;
//    return 0;
// }

int main()
{
   using namespace outer;
   using namespace inner;
   a=100;
   b=200;
   cout<<"Sum="<<a + b<<endl;
   return 0;
}