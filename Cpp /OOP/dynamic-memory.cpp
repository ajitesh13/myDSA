// #include <iostream>
// using namespace std;

// int main(){
//     int *p;
//     p = new int[5];
//     for(int i=0; i<5; i++){
//         cin>>p[i];
//     }
//     for(int j=0; j<5; j++){
//         cout<<"The value is: "<<p[j]<<endl;
//     }
//     delete []p;
//     for(int j=0; j<5; j++){
//         cout<<"The value is: "<<p[j]<<endl;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Point{
//     int x;
//     public:
//         void get(){
//             cin>>x;
//         }
//         void show(){
//             cout<<x<<endl;
//         }
// };

// int main(){
//     Point *p;
//     p = new Point;
//     p->get();
//     p->show();
//     delete p;
//     return 0;
// }

#include <iostream>
using namespace std;

class Point{
    int x;
    public:
        Point(){
                cout<<"Enter a value of x: ";cin>>x;
        }
        void show(){
            cout<<"x = "<<x<<endl;
        }
};

int main(){
    Point *p;
    p = new Point[5];
    for(int i=0; i<5; i++){
        p[i].show();
    }
    delete []p;
    return 0;
}