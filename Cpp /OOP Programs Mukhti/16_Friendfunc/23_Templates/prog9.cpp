#include<iostream>
using namespace std;

template<class T> class mystack
{
   T tarr[5];
   int top;
   public:
         void init()
		 {
		    top=-1; 
		 }
		 
         void push(T temp)
		 {
		    if(top>=4)
               cout<<"Stack Overflow"<<endl; 
            else {
                    top++;
                    tarr[top]=temp;
		         }
		 }
		 
		 void pop()
		 {
		    if(top<=-1)
               cout<<"Stack Underflow"<<endl;
            else {
                    cout<<"The popped element is "<<tarr[top]<<endl;
                    top--;
                 }
		 }
		 
		 void show() 
		 {
            if(top>=0) 
			{
               cout<<"Stack elements are:";
               for(int i=top; i>=0; i--)
                   cout<<tarr[i]<<" ";
                   cout<<endl;
            } 
			else
               cout<<"Stack is empty";
            }
};

int main()
{
   mystack<double> stack1;
   stack1.init();
   for(int k=0;k<5;k++)
   {
	   double dd;
	   cout<<"Push doubles onto the stack"<<endl;
	   cin>>dd;
       stack1.push(dd);
   }
   stack1.show();
   stack1.pop();
   stack1.show();
   cout<<"_____________________"<<endl;
   
      
   mystack<char> stack2;
   stack2.init();
   for(int k=0;k<5;k++)
   {
	   char cc;
	   cout<<"Push chars onto the stack"<<endl;
	   cin>>cc;
       stack2.push(cc);
   }
   stack2.show();
   stack2.pop();
   stack2.show();
   cout<<"__________________________"<<endl;
      
   return 0;
}