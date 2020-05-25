/*
overloading comparison operator
*/
/*
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
            bool operator==(Point rhs){
                if(rhs.x == this->x && rhs.y == this->y)
                    return true;
                else 
                    return false;
            }
};

int main(){
    Point p1(2, 3);
    Point p2(2, 3);
    if( p1 == p2){
        cout<<"p1 and p2 are equal";
    }
    else{
        cout<<"p1 and p2 are Not equal";
    }
    return 0;
}

*/
/*
    overloading the array indexing operator, array assignment 
    operator will generate error
*/
/*
#include <iostream>
using namespace std;

class Point{
    int arr[3];
        public:
            Point(){}
            Point(int a, int b, int c){
                arr[0] = a;
                arr[1] = b;
                arr[2] = c;
            }
            int operator[](int k){
                return arr[k];
            }
};

int main(){
    Point p1(10, 20, 30);
    cout<<p1[0]<<" "<<p1[1]<<" "<<p1[2]<<" "<<endl;
    return 0;
}
*/

/*
 if integer address is used in the return type, array assignment operator 
 can be used 
*/


#include <iostream>
using namespace std;

class Point{
    int arr[3];
        public:
            Point(){}
            Point(int a, int b, int c){
                arr[0] = a;
                arr[1] = b;
                arr[2] = c;
            }
            int& operator[](int k){
                return arr[k];
            }
};

int main(){
    Point p1(10, 20, 30);
    p1[0]=100;
    cout<<p1[0]<<" "<<p1[1]<<" "<<p1[2]<<" "<<endl;
    return 0;
}

