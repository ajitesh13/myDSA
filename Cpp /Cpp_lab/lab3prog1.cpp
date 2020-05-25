#include <iostream>
using namespace std;
class Base{
    int x;
    public:
        base(int i){
            x = i;
        }
        void show(){
            cout<<"x="<<x<<endl;
        }
};
class new_base{
    int a, b, c;
    public:
        new_base(int j, int k, int l){
            a = j;
            b = k;
            c = l;
        }
        void show1(){
            cout<<"a, b, and c = "<<a<<", "<<b<<" and "<<c<<endl;
        }
};
class derive:public base, public new_base{
    public:
        derive(int a, int b, int c, int d):base(a),new_base(b, c, d){
            cout<<"Derived Constructor"<<endl;
        }
};

int main(){
    derive ob(5, 10, 15, 20);
    ob.show();
    ob.show1();
    return 0;
}

