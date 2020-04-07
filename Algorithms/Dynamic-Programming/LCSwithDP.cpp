// lcs with DP

#include <bits/stdc++.h>
using namespace std;

void ln_lcs(string x, string y) {
	int m = x.length();
	int n = y.length();
	int c[m+1][n+1];
	int b[m+1][n+1];
	for (int i=0; i<=m; i++) {
		for (int j=0; j<=n; j++) {
			if (i==0 || j==0) {
				c[i][j] = 0;
				b[i][j] == 's';
			} else if (x.substr(0, i) == y.substr(0, j)) {
				c[i][j] = 1 + c[i-1][j-1];
				b[i][j] = 'd';
			} else if (x.substr(0, i) != y.substr(0, j)) {
				c[i][j] = max(c[i-1][j], c[i][j-1]);
				if (c[i-1][j] > c[i][j-1]) {
					b[i][j] = 'u';
				} else if (c[i][j-1] > c[i-1][j]) {
					b[i][j] = 'l';
				}
			}
		}
	}
	int index = c[m][n];
	char p[index+1];
	p[index] = '\0';
	int i = m, j = n;
	while (i > 0 && j > 0) {
		if (x[i-1] == y[j-1]) {
			p[index-1] = x[i-1];
			i--;
			j--;
			index--;
		} else if (c[i-1][j] > c[i][j-1]) {
			i--;
		} else if (c[i-1][j] < c[i][j-1]){
			j--;
		}
	}
	cout << p << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string x = "Ajitesh", y = "Ajit";
	// cin >> x >> y;
	ln_lcs(x, y);

	return 0;
}
