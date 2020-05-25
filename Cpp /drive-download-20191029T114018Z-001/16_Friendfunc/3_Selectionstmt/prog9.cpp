#include<iostream>
using namespace std;
int main()
{
  switch(5/2*6+3.0)
  {
     case 3: cout<<"Good"<<endl;
	         break;
	 case 15: cout<<"Bad"<<endl;
	         break;
	 default: cout<<"Bye"<<endl;
	         break;
  }
  return 0;
}