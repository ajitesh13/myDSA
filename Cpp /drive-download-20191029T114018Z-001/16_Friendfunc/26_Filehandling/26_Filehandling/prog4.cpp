#include<iostream>
#include<fstream>
using namespace std;

int main()
{
   fstream fstr("mybinfile",ios::out|ios::binary);
   int i;
   char c;
   double d;
   cout<<"Enter an integer"<<endl;
   cin>>i;
   cout<<"Enter a character"<<endl;
   cin>>c;
   cout<<"Enter a double"<<endl;
   cin>>d;
   fstr<<i<<c<<d;//writing to a bin file
   fstr.close();
   
   fstr.open("mybinfile",ios::in|ios::binary);
   int ii;
   char cc;
   double dd;
   cout<<"Integer \t"<<"Character\t"<<"Double"<<endl;
   fstr>>ii>>cc>>dd;//reading from a bin file
   cout<<ii<<"\t\t"<<cc<<"\t\t"<<dd<<endl;
   fstr.close();
   
   return 0;
}