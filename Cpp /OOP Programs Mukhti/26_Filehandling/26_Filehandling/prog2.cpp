#include<iostream>
#include<fstream>
using namespace std;

int main()
{
   ifstream in("Sample.txt");
   string s;
   /*while(in>>s)
   cout<<s;*/
   
   /*while(in>>s)
        cout<<s<<endl;*/
		
   while(in)
   {
        getline(in,s);
		cout<<s<<endl; 
   }

   return 0;
}
   
  