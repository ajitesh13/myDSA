#include <iostream>
using namespace std;

int find_square_root(int n){
	int i=0;
	while(i*i <= n){
		i++;
	}
	return (i-1);
}

int main(){
	int n;
	cin >> n;
	cout << find_square_root(n);
	return 0;
}