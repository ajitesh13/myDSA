#define L 10
#include<iostream>
using namespace std;
int main()
{
  int m=10;
  switch(m, m*2)
  {
     case L: cout<<"Good"<<endl;
	         break;
	 case L*2: cout<<"Bad"<<endl;
	         break;
	 case L*3: cout<<"Very bad"<<endl;
	         break;
	 default: cout<<"Bye"<<endl;
	 case L*4: cout<<"Very Good"<<endl;
	         break;
   }
  return 0;
}