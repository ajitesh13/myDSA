// #include <iostream>
// using namespace std;

// class Point{
//     int x;
//     public:
//         Point(){
//             x = 0;
//         }
//         Point(int a){
//             x = a;
//         }
//         friend int operator+(int lhs, Point rhs){
//             int temp;
//             temp = lhs + rhs.x;
//             return temp;
//         }
//         void display(){
//             cout<<"x = "<<x<<endl;
//         }
// };

// int main(){
//     Point p(10);
//     p.display();
//     int i = 200;
//     int z = i + p;
//     cout<<"z = "<<z<<endl;
//     return 0;
// }

/*
overloading assignment operator using member function
*/

#include <iostream>
using namespace std;

class Point{
    int x;
    public:
        Point(){
            x = 0;
        }
        Point(int a){
            x = a;
        }
        Point operator=(int rhs){
            this->x = rhs;
            return *this;
        }
        void display(){
            cout<<"x ="<<x<<endl;
        }
};

int main(){
    int m = 10;
    Point p1(30);
    p1.display();
    p1 = m;
    p1.display();
    return 0;
}