/* overloading the input and ouput stream operators */

#include<iostream>
using namespace std;

class Point
{
    int x,y;
	public:
	      //Point(int a,int b){x=a;y=b;}
		  friend ostream& operator<<(ostream& out, const Point &rhs);
		  friend istream& operator>>(istream& in, Point &rhs);
};


istream& operator>>(istream& in, Point &rhs)
{
    //cout<<"Enter a value for x"<<endl;
	in>>rhs.x;
	//cout<<"Enter a value for y"<<endl;
	in>>rhs.y;
	return in;
}

ostream& operator<<(ostream& out, const Point &rhs)
{
    out<<"x="<<rhs.x<<endl;
	out<<"y="<<rhs.y<<endl;
	return out;
}

int main()
{
   Point p;
   cout<<"Enter values for p"<<endl;
   cin>>p;
   cout<<"The values of p are:\n";
   cout<<p;
   return 0;
}