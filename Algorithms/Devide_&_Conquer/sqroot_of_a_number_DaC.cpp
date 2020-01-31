// find square root of a number using devide and conquer 
#include <iostream>
using namespace std;

int find_square_root(int n,int p) {
	if(p*p == n){
		return p;
	}else if(p*p > n){
		return p-1;
	}else{
		p++;
		find_square_root(n,p);
	}
}

int main() {
	int n;
	cin >> n;
	cout << find_square_root(n,1) << endl;
	return 0;
}