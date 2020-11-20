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

void solve() {
    int t = 1;
    // cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        priority_queue<pair<int,string>, vector<pair<int,string>>, compare> pq;
        pq.push(mp(1, "abc"));
        pq.push(mp(2, "abc"));
        pq.push(mp(4, "abcd"));
        pq.push(mp(4, "abcde"));
        while (!pq.empty()) {
            pair<int, string> p = pq.top();
            pq.pop();
            cout << p.first << ' ' << p.second << '\n';
        }
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
