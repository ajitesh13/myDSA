#include <iostream>
using namespace std;

int main() {
	int c;
	cin >> c;
	int l;
	cin >> l;
	int pre = c;
	int i=1;
	while (pre >= 0){
		i++;
		pre = pre + l;
		if (pre > c){
			pre = c;
		}
		pre = pre - i;
	}
	cout << i << endl;
	return 0;
}