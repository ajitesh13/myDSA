#include<iostream>
#include<fstream>
using namespace std;

int main()
{
   fstream fstr("mytext.txt", ios::out);
   fstr<<"This is my text file"<<endl;
   fstr.close();
   
   fstr.open("mytext.txt", ios::in);
   string s;
   while(fstr)
   {
       getline(fstr,s);
	   cout<<s;
   }
   fstr.close();
   return 0;
}