#include<iostream>
using namespace std;

class Point{
    public:
	    int x;
        int y;
        Point &getx(int i){
            x = i;
            return *this;
        }
        Point &gety(int j){
            y = j;
            return *this;
        }
        void display(){
            cout << "x=" << x << endl;
            cout << "y=" << y << endl;
        }
};

int main(){
   Point p;
   p.getx(10).gety(20).display();
   cout<<"_________________________\n"<<endl;
   cout<<"Check if actually x and y are initialized for p or not"<<endl;
   cout<<"x in p="<<p.x<<endl;
   cout<<"y in p="<<p.y<<endl;
   return 0;
}