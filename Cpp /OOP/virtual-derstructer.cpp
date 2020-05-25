#include <iostream>
using namespace std;

class Base{
    public:
        Base(){
            cout<<"Base class constructer"<<endl;
        }
        virtual ~Base(){
            cout<<"Base class destructer"<<endl;
        }
};

class Derived:public Base{
    public:
        Derived(){
            cout<<"Derived Constructor"<<endl;
        }
        ~Derived(){
            cout<<"Derived Destructor"<<endl;
        }
};

int main(){
    Base *pb;
    pb = new Derived;
    delete pb;
    return 0;
}
