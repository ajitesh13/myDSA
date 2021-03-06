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
   ifstream in("Accountfile", ios::in|ios::binary);
   cout<<"ID="<<"\t\t"<<"Balance"<<endl;
   cout<<"---------------------------------"<<endl;
   for(int i=0;i<3;i++)
   {
      in.read((char*)&account[i], sizeof(Account));
	  cout<<account[i].id<<"\t\t"<<account[i].balance<<endl;
	  //cout<<"Balance="<<<<endl;
   }
   in.close();
   
   return 0;
}