#include <iostream>
using namespace std;

class Container{
    protected:
        double x;
    public:
        virtual void initialise()=0;
        virtual void show_volume()=0;
};

class cube:public Container{
    public:
        void initialise(){
            cout<<"Enter length =  ";cin>>x;
        }
        void show_volume(){
            cout<<"Volume = "<<(x*x*x)<<endl;
        }
};

class Sphere:public Container{
    public:
        void initialise(){
            cout<<"Enter radius: ";cin>>x;
        }
        void show_volume(){
            cout<<"Volume of the sphere: "<<((double)4/3)*3.14*x*x*x<<endl;
        }
};

int main(){
    Container *c;
    cube cb;
    c = &cb;
    c->initialise();
    c->show_volume();
    Sphere s;
    c = &s;
    c->initialise();
    c->show_volume();
    return 0;

}
