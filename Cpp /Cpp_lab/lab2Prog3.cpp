#include <iostream>
using namespace std;

class Construct{
	private:	
		static int count;

	public: 
		Construct() {
            count++; 
        }
		static void out(){
			cout<<"Number of objects: "<<count<<endl;
		}
};


int Construct:: count = 0;

int main()
{
	Construct a;
	a.out();
	Construct b;
	b.out();
	Construct c;
	c.out();
    Construct d;
    d.out();
	return 0;
}
