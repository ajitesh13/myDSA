#include<iostream>
using namespace std;

template<class A, class B=int> class myclass
{
   A a;
   B b;
   public:
         void show(A temp1, B temp2)
		 {
		    a=temp1;
			b=temp2;
			cout<<"a="<<a<<" b="<<b<<endl;
		 }
};

int main()
{
   myclass<double,char> ob1;
   ob1.show(20.6,'F');
      
   myclass<double> ob2;
   ob2.show(30.9,100);
      
   return 0;
}