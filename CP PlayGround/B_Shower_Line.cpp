#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define printvec(x) for(int _=0;_<x.size();_++){cout<<x[_]<<' ';}cout<<'\n';
#define printvvec(x) for(int _=0;_<x.size();_++){for(int __=0;__<x[_].size(); __++){cout<<x[_][__]<<' ';}cout<<'\n';}
#define printmap(x) for(auto _=x.begin();_!=x.end();_++){cout<<_->f<<' '<<_->s<<'\n';}
#define printset(x) for(auto _=x.begin();_!=x.end();_++){cout<<*_<<' ';}cout<<'\n';
#define printvecp(x) for(int _=0;_<x.size();_++){cout<<x[_].f<<' '<<x[_].s<<'\n';}
#define printp(x) cout<<x.f<<' '<< x.s<<'\n';
#define fo(i,start,end) int i=start;i<end;i++
#define foi(i,start,end) int i=start;i<=end;i++
#define fot(it, x) auto it=x.begin();it!=x.end();it++
#define invec(v, n) for(int i=0;i<v.size();i++)cin>>v[i];
using namespace std;

// min-heap
class comp{
public:
    bool operator() (int& a, int& b) {
        return a > b;
    }
};

// sort pair
bool comp1(pair<int,int> a, pair<int,int> b) {
    return(a.second < b.second);
}

// string to int
int string_to_int(string s) {
    stringstream a(s);
    int x;
    a >> x;
    return x;
}

void solve() {
    int t = 1;
    // cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        vector<vector<int>> v(5, vector<int> (5, 0));
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                cin >> v[i][j];
            }
        }
        int mx = INT32_MIN;
        unordered_map<int,int> ump;
        priority_queue<pair<int,pair<int,int>>> pq;
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                pq.push({v[i][j] + v[j][i], {v[i][j], v[j][i]}});
            }
        }
        while (!pq.empty()) {
            cout <<  pq.top().first << ' ' << pq.top().second.first << ' ' << pq.top().second.second << '\n';
            pq.pop();
        }
        // int t1 = pq.top().first;
        // pq.pop();
        // pq.pop();
        // int t2 = pq.top().first;
        // pq.pop();
        // pq.pop();
        // int t3 = pq.top().first;
        // pq.pop();
        // pq.pop();
        // int t4 = pq.top().first;
        // cout << 2*t1+2*t2+t3+t4 << '\n';
        // cout << "Case #" << (google_contest_count+1) << ": ";google_contest_count++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        // freopen("in", "r", stdin);
        // freopen("out", "w", stdout);
    #endif
    
    solve();
    
    return 0;
}
