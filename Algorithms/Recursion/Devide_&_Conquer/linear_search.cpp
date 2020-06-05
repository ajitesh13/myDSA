#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	int item;
	cin >> item;
	int b = 0;
	for(int i=0; i<n; i++) {
		if(a[i] == item){
			b = i;
			break;
		}
	}
	cout << a[b] << endl;
	return 0;
}