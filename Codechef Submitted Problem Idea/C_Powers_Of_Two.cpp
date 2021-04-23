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
#define int long long int 

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

void best() {
    int __ = 1;
    // cin >> __;
    while(__--) {
        int n, k;
        cin >> n >> k;
        int index;
        for (int i=1; i<=32; i++) {
            if (pow(2, i) > n) {
                index = i-1;
                break;
            }
        }
        int pow2 = pow(2, index);
        int c = n - pow2;
        if (c != 0) {
            if (k >= 2 && k <= pow2 + 1) {
                deque<int> dq;
                dq.push_back(pow2);
                int d = k - 2;
                while (d--) {
                    int front = dq.front();
                    dq.pop_front();
                    for (int i=1; i<=2; i++) {
                        dq.push_back(front/2);
                    }
                }
                cout << "YES\n";
                for (int i=0; i<dq.size(); i++) cout << dq[i] << " ";
                cout << c << " ";
            } else cout << "NO\n";
        } else {
            if (k >= 1 && k <= pow2) {
                deque<int> dq;
                dq.push_back(pow2);
                int d = k - 1;
                while (d--) {
                    int front = dq.front();
                    dq.pop_front();
                    for (int i=1; i<=2; i++) {
                        dq.pb(front/2);
                    }
                }
                cout << "YES\n";
                for (int i=0; i<dq.size(); i++) cout << dq[i] << " ";
            } else cout << "NO\n";
        }
    }
}

signed main() {
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
