#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define printvec(x) for(int _=0;_<x.size();_++){cout<<x[_]<<' ';}cout<<'\n';
#define printvvec(x) for(int _=0;_<x.size();_++){for(int __=0;__<x[_].size(); __++){cout<<x[_][__]<<' ';}cout<<'\n';}
#define printmap(x) for(auto _=x.begin();_!=x.end();_++){cout<<_->first<<' '<<_->second<<'\n';}
#define printset(x) for(auto _=x.begin();_!=x.end();_++){cout<<*_<<' ';}cout<<'\n';
#define printvecp(x) for(int _=0;_<x.size();_++){cout<<x[_].first<<' '<<x[_].second<<'\n';}
#define printp(x) cout<<x.first<<' '<< x.second<<'\n';
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

// gcd
int gcd(int a, int b) {
    if (b == 0) return a;
    int temp = gcd(b, a%b);
    return temp;
}

vector<vector<int>> adj;
vector<int> visited;
int clash1 = 0, clash2 = 0;

void bfs(int source) {
    queue<int> q;
    q.push(source);
    visited[source] = -1;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int i: adj[top]) {
            if (visited[i] == 0) {
                if (visited[top] == -1) visited[i] = -2;
                q.push(i);
            } else if (visited[i] == -1) {
                if (visited[top] == -1) clash1 = 1;
            } else {
                if (visited[top] == -2) clash2 = 1;
            }
        }
    }
}

void virya() {
    int __;
    cin >> __;
    // int google_contest_count = 0;
    while(__--) {
        int n, e;
        cin >> n >> e;
        adj.assign(n+1, vector<int> ());
        for (int i=0; i<e; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        visited.assign(n+1, 0);
        bfs(1);
        for (int i=0; i<=n; i++) {
            cout << i << ": ";
            for (int j=0; j<adj[i].size(); j++) {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
        if (clash1 == 1 && clash2 == 1) {
            cout << 0 << "\n";
            for (int i=0; i<n; i++) {
                cout << 0;
            }
            cout << "\n";
        } else if (clash1 == 1 && clash2 == 0) {
            cout << 1 << "\n";
            for (int i=1; i<visited.size(); i++) {
                if (visited[i] == -1) {
                    cout << 0 << " ";
                } else cout << 1 << " ";
            } 
            cout << "\n";
        } else if (clash1 == 0 && clash2 == 1) {
            cout << 1 << "\n";
            for (int i=1; i<visited.size(); i++) {
                if (visited[i] == -2) {
                    cout << 0 << " ";
                } else cout << 1 << " ";
            } 
            cout << "\n";
        } else {
            cout << 2 << "\n";
            for (int i=1; i<visited.size(); i++) {
                if (visited[i] == -1) {
                    cout << 0 << " ";
                } else cout << 1 << " ";
            } 
            cout << "\n";
        }
        // cout << "Case #" << (google_contest_count+1) << ": ";google_contest_count++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        //freopen("in", "r", stdin);
        //freopen("out", "w", stdout);
    #endif
    
    virya();
    
    return 0;
}
