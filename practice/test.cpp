#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		bool pos=false, neg=false;
		vector<int> a(n);
		vector<int> b(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		for (int i=0; i<n; i++) {
			cin >> b[i];
		}
		if (a[0] != b[0]) {
			cout << "NO" << "\n";
		} else {
			if (a[0] > 0) {
				pos = true;
			}
			if (a[0] < 0) {
				neg = true;
			}
			int inr=0;
			for (int i=1; i<n; i++) {
				if (b[i] > a[i] && !pos) {
					cout << "NO" << "\n";
					inr++;
					break;
				} else if (b[i] < a[i] && !neg) {
					cout << "NO" << "\n";
					inr++;
					break;
				}
				if (a[i] > 0) {
					pos = true;
				}
				if (a[i] < 0) {
					neg = true;
				}
			}
			if (inr == 0) {
				cout << "YES" << "\n";
			}
		}
	}

	return 0;
}
