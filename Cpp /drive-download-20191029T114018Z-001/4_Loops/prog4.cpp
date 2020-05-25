#include<iostream>
using namespace std;
int main()
{
   static int i;
   for(++i;++i;++i)
   {
     cout<<i<<endl;
	 if(i==4)
	    break;
   }
	return 0;
}