#include <iostream>
using namespace std;

class A{
    private:
        int a;
    public:
        A(int i){
            a = i;
        }
        void display(){
            cout << a << endl;
        }
        
};