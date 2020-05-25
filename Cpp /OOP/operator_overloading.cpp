// overloading binary operator using member operator function

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
//         Point operator+(Point rhs){
//             Point temp;
//             temp.x = this->x + rhs.x;
//             temp.y = this->y + rhs.y;
//             return temp;
//         }
//         void display(){
//             cout<<"x = "<<x<<endl;
//             cout<<"y = "<<y<<endl;
//         }
// };

// int main(){
//     Point p1(2, 3), p2(3, 5);
//     Point p3;
//     p3 = p1 + p2;
//     p3.display();
//     return 0;
// }

//Ovrloading binary operator using non member operator function, the non-member 
//operator function cant use the attribute normally when they are in private form
//but if we make the function a friend function of the class then it can access all 
//attributes, even if they are private 

// #include <iostream>
// using namespace std;

// class Point{
//     //public:    
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
//         friend Point operator+(Point lhs, Point rhs);
//         void display(){
//             cout<<"x = "<<x<<endl;
//             cout<<"y = "<<y<<endl;
//         }
// };

// Point operator+(Point lhs, Point rhs){
//     Point temp;
//     temp.x = lhs.x + rhs.x;
//     temp.y = lhs.y + rhs.y;
//     return temp;
// }

// int main(){
//     Point p1(10, 20), p2(100, 200);
//     Point p3;
//     p3 = p1 + p2;
//     p3.display();
//     return 0;
// }

