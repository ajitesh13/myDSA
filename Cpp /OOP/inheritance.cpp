/*
    if in base class the data is protected then it can only be used in the derived 
    class not in the main.
    if in base class the data is private then in cant be accessed anywhere
    if the base class is set private, protected then its public attributes also cant be 
    accessed in main
*/

// #include <iostream>
// using namespace std;
// class Base{
//     protected:
//         int x;
// };
// class Derived:public Base{
//     public:
//         int y;
//         void show();
// };
// void Derived::show(){
//     x = 10;
//     y = 10;
//     cout<<"x = "<<x<<" "<<"y = "<<y<<endl;
// }
// int main(){
//     Derived d;
//     d.x = 30;
//     d.show();
//     return 0;
//}

// #include <iostream>
// using namespace std;
// class Base{
//     public:
//         int x;
// };
// class Derived1:public Base{
//     public:
//         int y;
// };
// class Derived2:public Derived1{
//     public:
//         int z;
// };
// int main(){
//     Derived2 d;
//     d.x = 1;
//     d.y = 2;
//     d.z = 3;
//     cout<<"Sum = "<<(d.x + d.y + d.z)<<endl;
//     return 0;
// }

//Diamond Inheritance Problem 

// #include <iostream>
// using namespace std;
// class Base{
//     public:
//         int x;
// };
// class Derived1:public Base{};
// class Derived2:public Base{};
// class Derived3:public Derived1, public Derived2{};
// int main(){
//     Derived3 d;
//     d.x = 10;
//     cout<<"x = "<<d3.x<<endl;
//     return 0;
// }

//Solution to Diamond Inheritance Problem 
//(code not working)

// #include <iostream>
// using namespace std;
// class Base{
//     public:
//         int x;
// };
// class Derived1:public Base{};
// class Derived2:public Base{};
// class Derived3:public Derived1, public Derived2{};
// int main(){
//     Derived3 d;
//     d.Derived1::x = 10;
//     d.Derived2::x = 20;
//     d.x = 30;
//     cout<<(d.Derived1::x + d.Derived2::x + d.x);
//     return 0;
// }

//Solution by virtual base 
/* virtual class create a single memory space of the base and the class derived after that */

// #include <iostream>
// using namespace std;
// class Base{
//     public:
//         int x;
// };
// class Derived1:public virtual Base{};
// class Derived2:public virtual Base{};
// class Derived3:public Derived1, public Derived2{};
// int main(){
//     Derived3 d;
//     d.x = 30;
//     d.Derived1::x=10;
//     d.Derived2::x=20;
//     cout<<(d.x);
//     return 0;
// }

/*   Stack approach of creation and deletion  */

// #include<iostream>
// using namespace std;

// class Base
// {
//    public:
//         Base(){cout<<"Base is created"<<endl;}
// 		~Base(){cout<<"Base is destroyed"<<endl;}
// };

// class Derived1:Base
// {
//    public:
//         Derived1(){cout<<"Derived1 is created"<<endl;}
// 		~Derived1(){cout<<"Derived1 is destroyed"<<endl;}
// };

// class Derived2:Derived1
// {
//    public:
//         Derived2(){cout<<"Derived2 is created"<<endl;}
// 		~Derived2(){cout<<"Derived2 is destroyed"<<endl;}
// };

// int main()
// {
//    Derived2 D2;
//    return 0;
// }

/* Out put is that of the Derived class */

// #include<iostream>
// using namespace std;

// class Base
// {
//    public:
//         int x;
// 		//solution 1 by providing a default base constructor
// 		Base(){}
//         Base(int i){x=i;}
// };

// class Derived:public Base
// {
//    public:
//         int y;
// 		Derived(){x=100; y=200;}
// };

// int main()
// {
//    Derived D;
//    cout<<"x in Derived="<<D.x<<endl;
//    cout<<"y in Derived="<<D.y<<endl;
//    return 0;
// }

/* Passing parameters to base class constructors */
// #include<iostream>
// using namespace std;

// class Base
// {
//    public:
//         int x;
// 		    Base(int i){x=i;}
// };

// class Derived:public Base
// {
//    public:
//         // solution 2 by passing parameters to base constructors
//         Derived(int j):Base(j)
// 		{x=j;}
// };

// int main()
// {
//    Derived D(20);
//    cout<<"x in Derived="<<D.x<<endl;
//    return 0;
// }

#include<iostream>
using namespace std;

class Base1
{
   public:
        int x;
		    Base1(int i){x=i;}
};

class Base2
{
   public:
        int p,q;
		    Base2(int i,int j){p=i; q=j;}
};
class Derived:public Base1,public Base2
{
   public:
        // solution 2 by passing parameters to base constructors
        Derived(int a,int b):Base1(a),Base2(a,b)
		{x=a; p=a; q=b;}
};

int main()
{
   Derived D(20,40);
   cout<<"x in Derived="<<D.x<<endl;
   cout<<"p in Derived="<<D.p<<endl;
   cout<<"q in Derived="<<D.q<<endl;
   return 0;
}



