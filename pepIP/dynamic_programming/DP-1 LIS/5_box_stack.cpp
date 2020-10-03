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

vector<tuple<int,int,int>> gen(vector<int> h, vector<int> w, vector<int> l, int n) {
    tuple<int,int,int> tu;
    vector<tuple<int,int,int>> vtu;
    for (int i=0; i<n; i++) {
        // h is h
        if (w[i] > l[i]) {
            vtu.pb(make_tuple(w[i], l[i], h[i]));
        } else {
            vtu.pb(make_tuple(l[i], w[i], h[i]));
        }

        // h is w
        if (h[i] > l[i]) {
            vtu.pb(make_tuple(h[i], l[i], w[i]));
        } else {
            vtu.pb(make_tuple(l[i], h[i], w[i]));
        }

        // if h is l 
        if (h[i] > w[i]) {
            vtu.pb(make_tuple(h[i], w[i], l[i]));
        } else {
            vtu.pb(make_tuple(w[i], h[i], l[i]));
        }
    }
    return vtu;
}

bool cmp(tuple<int,int,int> t1, tuple<int,int,int> t2) {
    if (get<0>(t1) == get<0>(t2)) {
        return(get<1>(t1) > get<1>(t2));
    } else {
        return(get<0>(t1) < get<0>(t2));
    }
}

int lis(vector<tuple<int,int,int>> vtu) {
    int res = 0;
    vector<int> dp(vtu.size());
    for (int j=0; j<vtu.size(); j++) {
        dp[j] = get<2>(vtu[j]);
        for (int i=0; i<j; i++) {
            if (get<1>(vtu[i]) < get<1>(vtu[j])) {
                if (dp[i] + get<2>(vtu[j]) > dp[j]) {
                    dp[j] = dp[i] + get<2>(vtu[j]);
                }
            }
        }
        res = max(res, dp[j]);
    }
    return res;
}

void solve() {
    int t = 1;
    // cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int n = 4;
        vector<int> h = {4, 1, 4, 10};
        vector<int> w = {6, 2, 5, 12};
        vector<int> l = {7, 3, 6, 32};
        vector<tuple<int,int,int>> process = gen(h, w, l, n);
        sort(process.begin(), process.end(), cmp);
        // for (int i=0; i<process.size(); i++) {
        //     cout << get<0>(process[i]) << ' ' << get<1>(process[i]) << ' ' << get<2>(process[i]) << '\n';
        // } 
        cout << lis(process) << '\n';
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
