#include<iostream>
using namespace std;

template<class A, class B> class myclass
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
   myclass<int,char> ob1;
   ob1.show(20,'F');
      
   myclass<double, const char*> ob2;
   ob2.show(30.9,"Hello");
      
   return 0;
}