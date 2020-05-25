#include <iostream>
using namespace std;

class A{
    private:
        int a;
    public:
        int a;
        void display(){
            cout << "a" << endl;
        }
        void A(int i){
            a = i;
        }
};