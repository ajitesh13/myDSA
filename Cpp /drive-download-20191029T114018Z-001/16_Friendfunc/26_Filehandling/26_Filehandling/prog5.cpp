/* Reading and writing blocks of binary data */

/* istream& read(char *buf, stremsize num);
   
   ostream& write(char *buf, streamsize num);  */
   

#include<iostream>
#include<fstream>
using namespace std;

struct Account
{
    int id;
	double balance;
};

int main()
{
   Account account[3];
   ofstream out("Accountfile", ios::out|ios::binary);
   for(int i=0;i<3;i++)
   {
      cout<<"Enter id"<<endl;
	  cin>>account[i].id;
	  cout<<"Enter balance"<<endl;
	  cin>>account[i].balance;
	  out.write((char*)&account[i], sizeof(Account));
   }
   
   out.close();
   return 0;
}