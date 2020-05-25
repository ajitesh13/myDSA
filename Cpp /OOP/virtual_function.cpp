#include <iostream>
using namespace std;

class A{
    public:
        int x;
        A(int a){
            x = a;
        }
        void show(){
            x = 100;
            cout<<"x = "<<x<<endl;
        }
};

int main(){
    A ob(5), *ptr;
    ptr = &ob;
    //cout<<"x = "<<(ptr->x)<<endl;
    ptr->show();
    return 0;
}