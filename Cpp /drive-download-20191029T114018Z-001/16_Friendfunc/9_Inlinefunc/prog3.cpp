#include<iostream>
using namespace std;

class Numbers
{
   int x,y;
   public:
        void get()
		{
          cout<<"Enter two integers"<<endl;
          cin>>x>>y;
        }
		int getbigger()
		{ return (x>=y?x:y); }
};

int main()
{
   Numbers n;
   n.get();
   cout<<"Bigger is="<<n.getbigger()<<endl;
   return 0;
}