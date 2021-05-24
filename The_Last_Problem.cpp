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
#define fo(i,start,end) int i=start;i<end;i++
#define foi(i,start,end) int i=start;i<=end;i++
#define fot(it, x) auto it=x.begin();it!=x.end();it++
#define invec(v, n) for(int i=0;i<v.size();i++)cin>>v[i];

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

vector<vector<int>> v;
void construct() {
    v.assign(1001, vector<int> (1001, 0));
    v[0][0] = 1;
    int vertinc = 2, horinc = 1;
    for (int i=1; i<1000; i++) {
        v[i][0] = vertinc + v[i-1][0];
        vertinc++;
    }
    for (int i=0; i<1000; i++) {
        int prehorinc = horinc;
        for (int j=1; j<1000; j++) {
            v[i][j] = horinc + v[i][j-1];
            horinc++;
        }
        prehorinc++;
        horinc = prehorinc;
    } 
    // for (int i=0; i<5; i++) {
    //     for (int j=0; j<5; j++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

void best() {
    construct();
    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        x1--;
        x2--;
        y1--;
        y2--;
        if (x1 > x2) {
            if (y1 > y2) {
                while (y1 != y2) {
                    sum += v[x1][y1];
                    y1--;
                }
                sum += v[x1][y1];
                while (x1 != x2) {
                    x1--;
                    sum += v[x1][y1];
                }
                cout << sum << "\n";
            } else if (y1 < y2) {
                while (y1 != y2) {
                    sum += v[x1][y1];
                    y1++;
                }
                sum += v[x1][y1];
                while (x1 != x2) {
                    x1--;
                    sum += v[x1][y1];
                }
                cout << sum << "\n";
            } else {
                while (x1 != x2) {
                    sum += v[x1][y1];
                    x1--;
                }
                sum += v[x1][y1];
                cout << sum << '\n';
            }
        } else if (x1 < x2) {
            swap(x1,x2);
            swap(y1,y2);
            if (y1 > y2) {
                while (y1 != y2) {
                    sum += v[x1][y1];
                    y1--;
                }
                sum += v[x1][y1];
                while (x1 != x2) {
                    x1--;
                    sum += v[x1][y1];
                }
                cout << sum << "\n";
            } else if (y1 < y2) {
                while (y1 != y2) {
                    sum += v[x1][y1];
                    y1++;
                }
                sum += v[x1][y1];
                while (x1 != x2) {
                    x1--;
                    sum += v[x1][y1];
                }
                cout << sum << "\n";
            } else {
                while (x1 != x2) {
                    sum += v[x1][y1];
                    x1--;
                }
                sum += v[x1][y1];
                cout << sum << '\n';
            }
        } else {
            if (y1 > y2) {
                while (y1 != y2) {
                    sum += v[x1][y1];
                    y1--;
                }
                sum += v[x1][y1];
                cout << sum << "\n";
            } else if (y1 < y2) {
                while (y1 != y2) {
                    sum += v[x1][y1];
                    y1++;
                }
                sum += v[x1][y1];
                cout << sum << "\n";
            } else {
                sum += v[x1][y1];
                cout << sum << '\n';
            }
        }
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
