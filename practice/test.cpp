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

	int N = 2;
	vector<vector<int>> trust = {{1,2}};
	int n = N;
	int e = trust.size();
	int a, b;
	vector<vector<int>> adj(n);
	for (auto i: trust) {
		a = i[0];
		b = i[1];
		adj[b-1].push_back(a);
	}
	// for (int i=0; i<n; i++) {
	// 	cout << (i+1) << ": ";
	// 	for (auto it=adj[i].begin(); it!=adj[i].end(); it++) {
	// 		cout << *it << " ";
	// 	}
	// 	cout << endl;
	// }
	int res = -1;
	for (int i=0; i<n; i++) {
		int x = adj[i].size();
		if (x > res) {
			cout << "in" << endl;
			res = adj[i].size();
		}
	}
	cout << res << endl;

	return 0;
}
