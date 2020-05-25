#include <iostream>
using namespace std;

class Container{
    protected:
        double x;
    public:
        virtual void init()=0;
        virtual void volume()=0;
};

class cube:public Container{
    public:
        void init(){
            cout<<"Enter length =  ";cin>>x;
        }
        void volume(){
            cout<<"Volume = "<<(x*x*x)<<endl;
        }
};

class Sphere:public Container{
    public:
        void init(){
            cout<<"Enter radius: ";cin>>x;
        }
        void volume(){
            cout<<"Volume of the sphere: "<<((double)4/3)*3.14*x*x*x<<endl;
        }
};

int main(){
    Container *c;
    cube cb;
    c = &cb;
    c->init();
    c->volume();
    Sphere s;
    c = &s;
    c->init();
    c->volume();
    return 0;

}