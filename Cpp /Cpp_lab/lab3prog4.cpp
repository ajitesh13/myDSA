#include <iostream>
using namespace std;

class Base{
    private:
        Base(){
            cout<<"Constructor of the Base class"<<endl;
        }
};

class Derived:Base{
    public:
        Derived(){
            cout<<"Constructor of the Derived Class"<<endl;
        }
};

int main(){
    Derived d;
    return 0;
}
