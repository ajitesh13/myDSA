// #include <iostream>
// using namespace std;

// class A{
//     public:
//         int x;
//         int y;
//         A(int a, int b){
//             this->x = a;
//             this->y = b;
//         }
//         void display(){
//             cout<<"x = "<<(this->x)<<endl;
//             cout<<"y = "<<(this->y)<<endl;
//         }
// };

// int main(){
//     A ob1(2, 3);
//     ob1.display();
//     return 0;
// }

#include <iostream>
using namespace std;

int& f(int a){
    int *p = &a;
    return *p;
}

int main(){
    int x = 100;
    cout<<f(x)<<endl;
    return 0;
}

