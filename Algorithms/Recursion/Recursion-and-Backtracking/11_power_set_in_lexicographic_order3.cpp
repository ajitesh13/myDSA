// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define make_pair mp
using namespace std;
const int MAX = 10e6;
vector<string> res;

double tick() {
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}

void gen(string str, int index = -1, string curr = "") {
    int max = pow(2, str.size());
    for (int i=0; i<max; i++) {
        string cp = "";
        for (int j=0; j<3; j++) {
            if (i&(1<<j)) {
                // if (j == 0) cout << 'a';
                if (j == 0) cp.pb('a');
                // if (j == 1) cout << 'b';
                if (j == 1) cp.pb('b');
                // if (j == 2) cout << 'c';
                if (j == 2) cp.pb('c');
            }
        }
        res.pb(cp);
        cp.clear();
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif
    
    string str;
    cin >> str;
    gen(str);
    sort(res.begin(), res.end());
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            cout << res[i][j];
        }
        cout << '\n';
    }
    
    cerr << "\n\n**ET : " << tick() << "**\n";
    return 0;
}
