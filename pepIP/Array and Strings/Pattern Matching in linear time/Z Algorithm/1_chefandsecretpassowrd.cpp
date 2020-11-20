// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
using namespace std;
const int MAX = 10e6;

double tick() {
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}

class compare {
public:
    bool operator() (pair<int,string> p1, pair<int,string> p2) {
        if (p1.first < p2.first) {
            return true;
        } else if (p1.first > p2.first) {
            return false;
        } else {
            if (p1.second.size() < p2.second.size()) {
                return true;
            } else if (p1.second.size() > p2.second.size()) {
                return false;
            } else {
                return false;
            }
        }
    }
};

vector<int> Zarr(string st) {
    int n = st.length();
    vector<int> Z(st.length(), 0);
    int L = 0, R = 0;
    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && st[R - L] == st[R])
                R++;
            Z[i] = R - L;
            R--;
        } else {
            int k = i - L;
            if (Z[k] < R - i + 1)
                Z[i] = Z[k];
            else {
                L = i;
                while (R < n && st[R - L] == st[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
    return Z;
}

int Zalgo(string txt, string pat) {
    string final = pat + "#" + txt;
    vector<int> z = Zarr(final);
    vector<int> res;
    for (int i=0; i<z.size(); i++) {
        if (z[i] == pat.size()) {
            res.pb(i-pat.size()-1);
        }
    }
    return res.size();
}

void solve() {
    int t;
    cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        priority_queue<pair<int, string>, vector<pair<int,string>>, compare> pq;
        for (int i=1; i<str.size()+1; i++) {
            int res = Zalgo(str, str.substr(0, i));
            pq.push(mp(res, str.substr(0, i)));
        }
        pair<int, string> p;
        p = pq.top();
        cout << p.second << '\n';
        // while (!pq.empty()) {
        //     pair<int, string> p = pq.top();
        //     pq.pop();
        //     cout << p.first << ' ' << p.second << '\n';
        // }
        // cout << "Case #" << (google_contest_count+1) << ": ";google_contest_count++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        // freopen("out", "w", stdout);
    #endif
    
    solve();
    
    #ifndef ONLINE_JUDGE
        cerr << "\n**ET : " << tick() << "**\n";
    #endif
    
    return 0;
}
