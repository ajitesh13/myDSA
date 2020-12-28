#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
#define f first
#define s second
using namespace std;

// min-heap
class comp{
public:
    bool operator() (int& a, int& b) {
        return a > b;
    }
};

// sort pair
bool comp1(pair<char,int> a, pair<char,int> b) {
    return(a.second > b.second);
}

void solve() {
    int t;
    cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        string s;
        cin >> s;
        unordered_map<char,int> ump;
        for (int i=0; i<s.size(); i++) {
            if (ump.find(s[i]) == ump.end()) {
                ump.insert({s[i], 1});
            } else {
                ump[s[i]]++;
            }
        }
        // for (auto it=ump.begin(); it!=ump.end(); it++) {
        //     cout << it->first << ' ' << it->second << '\n';
        // }
        int res = 0;
        for (auto it=ump.begin(); it!=ump.end(); it++) {
            if (it->second >= 3) {
                int groups = it->second/3;
                res += groups;
                it->second = it->second - 3*groups;
            }
        }
        vector<pair<char,int>> v;
        for (auto it=ump.begin(); it!=ump.end(); it++) {
            if (it->second != 0) {
                v.pb({it->first, it->second});
            }
        }
        sort(v.begin(), v.end(), comp1);
        // for (int i=0; i<v.size(); i++) {
        //     cout << v[i].first << ' ' << v[i].second << '\n';
        // }
        for (int i=0; i<v.size(); i++) {
            if (v[i].second == 2) {
                for (int j=i+1; j<v.size(); j++) {
                    if (v[j].second >= 1) {
                        v[j].second--;
                        v[i].second = 0;
                        res++;
                        break;
                    }
                }
            }
            
        }
        cout << res << '\n';
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
    
    return 0;
}
