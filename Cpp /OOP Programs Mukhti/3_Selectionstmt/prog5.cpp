#include<iostream>
using namespace std;
int main()
{
  int m=1;
  switch(m<<2+m)
  {
     default: cout<<"Bye"<<endl;
	 case 4: cout<<"4"<<endl;
	 case 5: cout<<"5"<<endl;
	 case 8: cout<<"8"<<endl;
	 
   }
   
  return 0;
}