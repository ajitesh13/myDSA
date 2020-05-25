#include <iostream>
using namespace std;
class classA{
    public:
    int a;
}

class classB:public ClassA{
    public:
        int b;
}

class classC:public classA{
    public:
        int c;
}

class classD:public classB, public classC{

}