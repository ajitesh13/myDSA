#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define cont(it,x) for (auto it=x.begin(); it!=x.end(); it++){cout << *it << ' ';} cout << '\n';
#define contp(it,x) for (auto it=x.begin(); it!=x.end(); it++){cout << it->first << ' ' << it->second << '\n';}
#define printvvec(x) for(int _=0;_<x.size();_++){for(int __=0;__<x[_].size(); __++){cout<<x[_][__]<<' ';}cout<<'\n';}
#define printp(x) cout<<x.first<<' '<< x.second<<'\n';
#define fo(i,start,end) int i=start;i<end;i++
#define foi(i,start,end) int i=start;i<=end;i++
#define fot(it, x) auto it=x.begin();it!=x.end();it++
#define printadj(n,x) for (int i=0; i<n; i++) {cout<<i<<": ";for(int j=0;j<x[i].size();j++){cout<<adj[i][j]<<' ';}cout<<'\n';}
//#define int long long int

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

int n, m;
vector<vector<int>> v;
vector<vector<bool>> visit;

vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,-1,0,1};

bool isvalid(int x, int y) {
    if (x >= 0 and x < n and y >= 0 and y < m) return true;
    else return false;
}

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    v[x][y] = 0;
    visit[x][y] = true;

    while (!q.empty()) {
        int topx = q.front().first;
        int topy = q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            int newx = topx + dx[i];
            int newy = topy + dy[i];
            if (isvalid(newx, newy) and !visit[newx][newy]) {
                visit[newx][newy] = true;
                v[newx][newy] = v[topx][topy] + 1;
                q.push({newx,newy});
            }
        }

    }
}
void best() {
    int __ = 1;
    // cin >> __;
    while(__--) {
        cin >> n >> m;
        v.assign(n, vector<int> (m));
        visit.assign(n, vector<bool> (m));
        bfs(4,4);
        printvvec(v);
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
    
    best();
    
    return 0;
}
