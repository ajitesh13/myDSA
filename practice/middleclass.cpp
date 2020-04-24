#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) {
		int n, hw;
		cin >> n >> hw;
		vector<int> v(n);
		for (int i=0; i<n; i++) {
			cin >> v[i];
		}
		sort(v.rbegin(), v.rend());
		int ans=0, s=0;
		for (int i=0; i<n; i++) {
			s += v[i];
			if ((i+1)*hw <= s) {
				ans++;
				continue;
			} else {
				break;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
