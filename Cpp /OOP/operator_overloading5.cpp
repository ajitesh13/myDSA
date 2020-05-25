// #include <iostream>
// using namespace std;

// class Point{
//     int x;
//     int y;
//     int z;
//     public:
//         Point(){
//             x = 0;
//             y = 0;
//             z = 0;
//         }
//         Point(int a, int b, int c){
//             x = a;
//             y = b;
//             z = c;
//         }
//         Point operator()(int a){
//             x = a;
//             return *this;
//         }
//         Point operator()(int a, int b){
//             x = a;
//             y = b;
//             return *this;
//         }
//         Point operator()(int a, int b, int c){
//             x = a;
//             y = b;
//             z = c;
//             return *this;
//         }
//         void show(){
//             cout<<"x = "<<x<<endl;
//             cout<<"y = "<<y<<endl;
//             cout<<"z = "<<z<<endl;
//         }
// };

// int main(){
//     Point p;
//     p.show();
//     p(100);
//     p.show();
//     p(100, 200);
//     p.show();
//     p(100, 200, 300);
//     p.show();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Point{
//     int x;
//     public:
//         Point(int a){
//             x = a;
//         }
//         void show(){
//             cout<<"x = "<<x<<endl;
//         }
//         operator int(){
//             return x;
//         }
// };

// int main(){
//     Point p(100);
//     p.show();
//     int i = p;
//     cout<<"i = "<<i<<endl;
//     return 0;
// }

#include <iostream>
using namespace std;

class Complex{
    int real;
    int img;
    public:
        Complex(){}
        Complex(int a, int b){
            real = a;
            img = b;
        }
        Complex operator*(Complex rhs){
            real = real*rhs.real - img*rhs.img;
            img = img*rhs.real + real*rhs.img;
        }
        void show(){
            cout<<"real = "<<real<<endl;
            cout<<"img = "<<img<<endl;
        }
};

int main(){
    Complex c1(1, 2), c2(4, 5);
    Complex c3;
    c3 = c1*c3;
    c3.show();
    return 0;
}