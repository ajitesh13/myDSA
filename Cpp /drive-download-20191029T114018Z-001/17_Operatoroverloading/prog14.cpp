/* Checking array boundary values */

#include<iostream>
using namespace std;

class Point
{
   int arr[3];
   public:
        Point(){}
		Point(int a,int b,int c)
		{
		   arr[0]=a;
		   arr[1]=b;
		   arr[2]=c;
		}
		int& operator[](int k)
		{
		  if(k<0||k>2)
		  {
		    cout<<"You are trying to access beyond the array boundary. Program will be terminated!!!"<<endl;
			exit(1);
		  }
		  else
		    return arr[k];
		}
};

int main()
{
   Point p(10,20,30);
   cout<<"First element="<<p[0]<<endl;
   cout<<"Second element="<<p[1]<<endl;
   cout<<"Third element="<<p[2]<<endl;
   p[0]=100;// no error
   cout<<"The new value of p[0]="<<p[0]<<endl;
   p[3]=300;//Will flag a warning as accesing is beyond the array boundary
   return 0;
}