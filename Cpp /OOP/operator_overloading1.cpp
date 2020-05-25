#include <iostream>
using namespace std;

class Point{
        int x;
        int y;
    public:
        Point(){
            x = 0;
            y = 0;
        }
        Point(int a, int b){
            x = a;
            y = b;
        }
        Point operator++(){
            x++;
            y++;
            return *this;
        }
        void display(){
            cout<<"x = "<<x<<endl;
            cout<<"y = "<<y<<endl;
        }
};

int main(){
    Point p1(10, 20);
    Point p2=++p1;
    p2.display();
    return 0;
}

/* A reference parameter is required,in the this pointer
as it is a non-member function
and it does not have a *this pointer */

// #include <iostream>
// using namespace std;

// class Point{    
//         int x;
//         int y;
//     public:
//         Point(){
//             x = 0;
//             y = 0;
//         }
//         Point(int a, int b){
//             x = a;
//             y = b;
//         }
//         friend Point operator++(Point &rhs){
//             rhs.x++;
//             rhs.y++;
//         }
//         void display(){
//             cout<<"x = "<<x<<endl;
//             cout<<"y = "<<y<<endl;
//         }
// };

// int main(){
//     Point ob1(2, 3);
//     ++ob1;
//     ob1.display();
//     return 0;
// }





