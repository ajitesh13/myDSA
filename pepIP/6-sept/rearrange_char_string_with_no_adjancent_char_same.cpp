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

struct key {
    int freq;
    char ch;

    bool operator<(const key &k) const {
        return freq < k.freq;
    }
};

void solve() {
    int t;
    cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        vector<int> count(26);
        unordered_map<char, int> um;
        for (int i=0; i<str.size(); i++) {
            if (um.find(str[i]) == um.end()) {
                um.insert(mp(str[i], 1));
            } else {
                um[str[i]]++;
            }
        }
        priority_queue<key> pq;
        for (auto it = um.begin(); it != um.end(); it++) {
            pq.push({it->second, it->first});
        }

        string res = "";
        key temp = {'#', '-1'};
        while (!pq.empty()) {
            if (temp.ch != '#') {
                pq.push(temp);
            }
            key k = pq.top();
            pq.pop();
            res += k.ch;
            k.freq--;
            if (k.freq > 0) {
                pq.push({k.ch, k.freq});
            }
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
