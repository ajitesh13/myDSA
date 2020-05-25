#include <iostream>
using namespace std;

#define pi=22/7;

class Figure{
    protected:
        double x;
    public:
        Figure(){
            cout<<"Enter Attribute:";
            cin>>x;
        }
        virtual void show_area()=0;
};

class Square:public Figure{
    public:
        void show_area(){
            cout<<"Area = "<<(x*x)<<endl;
        }
};

class Circle:public Figure{
    public:
        void init(){
            cout<<"Enter radius: ";cin>>x;
        }
        void show_area(){
            cout<<"Area of the circle "<<(pi*x*x)<<endl;
        }
};

int main(){
    Square s;
    s.show_area();
    Circle c;
    c.show_area();
    return 0;
}
