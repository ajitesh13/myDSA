#include <iostream>

using namespace std;
class ClassA
{
public:
    int a;
};

class ClassB : virtual public ClassA
{
public:
    int b;
};
class ClassC : virtual public ClassA
{
public:
    int c;
};

class ClassD : public ClassB, public ClassC
{
public:
    int d;
};

int main()
{

    ClassD obj;

    obj.a = 10;
    /**In the above example, both ClassB & ClassC inherit ClassA, they both have single copy of ClassA.
    However ClassD inherit both ClassB & ClassC, therefore ClassD have two copies of ClassA, one from ClassB and another from ClassC.
    If we need to access the data member a of ClassA through the object of ClassD, we must specify the path from which a will be accessed,
    whether it is from ClassB or ClassC, because compiler can't differentiate between two copies of ClassA in ClassD
    **/
    obj.b = 20;
    obj.c = 30;
    obj.d = 40;

    cout<< "\n A : "<< obj.a;
    cout<< "\n B : "<< obj.b;
    cout<< "\n C : "<< obj.c;
    cout<< "\n D : "<< obj.d;
    return 0;

}
