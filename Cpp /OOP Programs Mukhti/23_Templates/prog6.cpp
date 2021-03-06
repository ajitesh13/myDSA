#include<iostream>
using namespace std;

template<class A> class myclass
{
   A a;
   public:
         void show(A temp)
		 {
		    a=temp;
			cout<<"a="<<a<<endl;
		 }
};

int main()
{
   myclass<int> ob1;
   ob1.show(20);
   ob1.show(100.5);
   
   myclass<char> ob2;
   ob2.show('D');
   ob2.show(66);
   
   return 0;
}