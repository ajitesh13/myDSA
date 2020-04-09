#include <bits/stdc++.h>
using namespace std;

void check(int ar[], int br[], int p, int q) {
	if (p < q) {
		if (br[p] < ar[p]) {
			int inr=0;
			for (int i=0; i<p; i++) {
				if (ar[i] == -1) {
					inr++;
				}
			}
			if (inr != 0) {
				p++;
				check(ar, br, p, q);
			} else {
				cout << "NO" << "\n";
			}
		} else if (br[p] > ar[p]) {
			int inr=0;
			for (int i=0; i<p; i++) {
				if (ar[i] == 1) {
					inr++;
				}
			}
			if (inr != 0) {
				p++;
				check(ar, br, p, q);
			} else {
				cout << "NO" << "\n";
			}
		} else {
			p++;
			check(ar, br, p, q);
		}
	} else {
		cout << "YES" << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n], br[n];
		for (int i=0; i<n; i++) {
			cin >> ar[i];
		}
		for (int j=0; j<n; j++) {
			cin >> br[j];
		}
		if (ar[0] != br[0]) {
			cout << "NO" << "\n";
		} else {
			check(ar, br, 1, n-1);
		}
	}
	return 0;
}
