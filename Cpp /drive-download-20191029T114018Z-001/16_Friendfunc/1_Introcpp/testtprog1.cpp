#include<iostream>
//using namespace std;
int main()
{
   int x(2000);// implicit initialization
   std::cout<<"x is initialized to "<<x<<std::endl;
   std::cout<<"Hello world"<<std::endl;
   std::cout<<"Enter a value for x"<<std::endl;
   std::cin>>x;
   std::cout<<"x="<<x<<std::endl;
   x=1000;// explicit initialization
   std::cout<<"now x="<<x<<std::endl;
   const int K=10000;
   K=2000;
   std::cout<<"K="<<K<<std::endl;
   return 0;
}
