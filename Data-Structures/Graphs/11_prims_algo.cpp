// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
#define MAX 10e5
//#define MAX 10e4
using namespace std;
vector<vector<pair<int,int>>> v(MAX);
vector<bool> check(MAX);

int prims(int x) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push(make_pair(0, x));
    int mincost = 0;
    while (!q.empty()) {
        auto i = q.top();
        q.pop();
        int x = i.second;
        int cost = i.first;
        if (check[x] == true) {
            continue;
        }
        check[x] = true;
        mincost += cost;
        for (int i=0; i<v[x].size(); i++) {
            int y = v[x][i].second;
            if (check[y] == true) {
                continue;
            }
            q.push(v[x][i]);
        }
    }
    return mincost;
}

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, e;
    cin >> n >> e;
    int x, y, z;
    for (int i=0; i<e; i++) {
        cin >> x >> y >> z;
        v[x].push_back(make_pair(z, y));
        v[y].push_back(make_pair(z, x));
    }
    int mincost = prims(1);
    cout << mincost << endl;
    
    return 0;
}
