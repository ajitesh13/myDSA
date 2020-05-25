/* concatenating multiple function calls */
#include<iostream>
using namespace std;

class Point
{
    public:
	    int x;
        int y;
         Point& getx(int i)
		 {
		    x=i;
			return *this;
		 }
		 Point& gety(int j)
		 {
		    y=j;
			return *this;
		 }
		 
		 /*Point getx(int i)
		 {
		    x=i;// Will initialize x for p
			return *this;// this pointer points to an anonymous object
		 }
		 Point gety(int j)
		 {
		    y=j;// Will initialize y for anonymous object
			return *this;
		 }*/
		 
		 /*Point* getx(int i)
		 {
		    x=i;// Will initialize x for p
			return this;//returns a pointer pointing to p
		 }// but, have to use -> instead of .
		 Point* gety(int j)
		 {
		    y=j;//will initialize y for p
			return this;// returns a pointer pointing to p
		 }// but, have to use -> instead of . */
		 
		 /*Point getx(int i)
		 {
		    Point temp;
			x=i;//will initialize x for p
			temp.x=i;
			return temp;// returns temp which is not p
		 }
		 Point gety(int j)
		 {
		    Point oth;
			y=j;// y is initialized for an anonymous object
			oth.y=j;
			return oth;
		 }*/
		 
		 void display()
		 {
		    cout<<"x="<<x<<endl;
			cout<<"y="<<y<<endl;
		 }
};

int main()
{
   Point p;
   //p.getx(10)->gety(20)->display();
   p.getx(10).gety(20).display();
   cout<<"_________________________\n"<<endl;
   cout<<"Check if actually x and y are initialized for p or not"<<endl;
   cout<<"x in p="<<p.x<<endl;
   cout<<"y in p="<<p.y<<endl;
   return 0;
}