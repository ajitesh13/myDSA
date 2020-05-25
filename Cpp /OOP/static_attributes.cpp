/*
    Static member function doesnt have a this pointer. and static attributes can be 
    used directly from static member function. and normal attributes cant be accessed
    from any static member function.
*/

// #include <iostream>
// using namespace std;

// class A{
//     public:
//         static int si; //declared only
// };

// int A::si; //defined and stored

// int main(){
//     A::si = 10;
//     cout<<"si = "<<A::si<<endl;
//     A ob1;
//     cout<<"si for object is: "<<A::si<<endl;
//     A::si++;
//     cout<<"Updated si for object is: "<<A::si<<endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class A{
//         int i;
//         static int si;
//     public:
//         static void sf(){
//             si = 20;
//             A::i = 10;
//             cout<<"si = "<<si<<endl;
//             cout<<"A::i = "<<i<<endl;
//         }
// };

// int A::si;

// int main(){
//     A ob1;
//     ob1.sf();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// class A{
//         static int si;
//         int i;
//     public:
//         static void sf(){
//             si = 20;
//             cout<<"Accessing static si in static sf = "<<si<<endl;
//         }
// };
// int A::si;
// int main(){
//     cout<<"Through Class Name: ";
//     A::sf();
//     A ob1;
//     cout<<"Through Object: ";
//     ob1.sf();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// class A{
//         static int si;
//     public:
//         A(){
//             si++;
//             cout<<"Number of objected created are: "<<si<<endl;
//         }
// };
// int A::si;
// void nonmemfunc(){
//     A ob4;
// }
// int main(){
//     A ob1, ob2, ob3;
//     nonmemfunc();
//     return 0;
// }


#include <iostream>
using namespace std;

class A{
        static int si;
    public:
        A(){
            si++;
            cout<<"class no."<<si<<"is created"<<'\n';
        }
        ~A(){
            cout<<"class no."<<si<<"is destroyed"<<'\n';
            si--;
        }
};

int A::si;

int main(){
    A ob1, ob2, ob3;
    return 0;
}