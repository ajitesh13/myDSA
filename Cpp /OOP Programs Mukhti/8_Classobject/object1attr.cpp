/* Member attributes are allocated per object basis. Individual 
   copies of attributes are available to individual objects. Thus,
   each object has its own attribute values. But, static attributes
   are shared by all the objects of a class. */
   
#include<iostream>
using namespace std;

class Myclass
{
   public:
        int x,y;
};

int main()
{
   Myclass ob1,ob2;
   ob1.x=10;
   ob2.y=200;
   cout<<"x in ob1="<<ob1.x<<endl;
   cout<<"x in ob2="<<ob2.x<<endl;
   cout<<"______________________"<<endl;
   cout<<"y in ob1="<<ob1.y<<endl;
   cout<<"y in ob2="<<ob2.y<<endl;
   cout<<"______________________"<<endl;
   
   ob1.x++;
   cout<<"x in ob1="<<ob1.x<<endl;
   cout<<"x in ob2="<<ob2.x<<endl;
   cout<<"______________________"<<endl;
   
   ob2.y++;
   cout<<"y in ob1="<<ob1.y<<endl;
   cout<<"y in ob2="<<ob2.y<<endl;
   cout<<"______________________"<<endl;
   
   return 0;
}