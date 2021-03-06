#include<iostream>
using namespace std;
enum factor{f1=5, f2=-2, f3, f4};
int main()
{
  int x=0;
  switch(x)
  {
     case f1: cout<<"Good"<<endl;
	         break;
	 case f2: cout<<"Bad"<<endl;
	         break;
	 case f3: cout<<"Very bad"<<endl;
	         break;
	 case f4: cout<<"Very Good"<<endl;
	         break;
   }
  return 0;
}