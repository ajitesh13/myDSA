/*
overloading a unary postfix operator using meber function using a dummy variable
*/

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
//         Point operator++(int dummy){
//             x++;
//             y++;
//             return *this;
//         }
//         void display(){
//             cout<<"x = "<<x<<endl;
//             cout<<"y = "<<y<<endl;
//         }
// };

// int main(){
//     Point p1(10, 20);
//     p1++;
//     p1.display();
//     return 0;
// }


// #include <iostream>
// using namespace std;

// class Point{
//     int x;
//     int y;
//     public:
//         Point(int a, int b){
//             x = a;
//             y = b;
//         }
//         friend Point operator++(Point &ref, int dummy){
//             ref.x++;
//             ref.y++;
//             return ref;
//         }
//         void display(){
//             cout<<"x = "<<x<<endl;
//             cout<<"y = "<<y<<endl;
//         }
// };

// int main(){
//     Point p1(2, 3);
//     p1++;
//     p1.display();
//     return 0;
// }