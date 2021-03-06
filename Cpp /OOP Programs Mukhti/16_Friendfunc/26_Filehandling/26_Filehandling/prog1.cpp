#include<iostream>
#include<fstream>
using namespace std;

int main()
{
   ofstream out("Sample.txt"); // File is created through a constructor
   out<<"This is line one"<<endl;
   out<<"This is line two"<<endl;
   
   ofstream out1;
   out1.open("Sample2.txt",ios::out); // open() method has been used to creat a file
   out1<<"This is line three"<<endl;
   out1<<"This is line four"<<endl;
   out1.close();
   return 0;
}