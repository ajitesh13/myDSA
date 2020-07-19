// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
using namespace std;

// int main() {
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	vector<int> a = { 1, 2, 3, 4, 5 };
	if (find(a.begin(), a.end(), 5) != a.end()) {
		cout << "PRESENT SIR" << endl;
	} else {
		cout << "NOT PRESENT SIR" << endl;
	}
	
	return 0;
}
