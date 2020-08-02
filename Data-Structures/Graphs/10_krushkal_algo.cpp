// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = 10e4;
vector<pair<int,pair<int,int>>> v(MAX);
vector<int> id(MAX);
int n, e;

void initialize() {
    for (int i=0; i<MAX; i++) {
        id[i] = i;
    }
}

int root(int x) {
    while (id[x] != x) {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void join(int x, int y) {
    id[root(x)] = id[root(y)];
}

int krushkal(vector<pair<int,pair<int,int>>> v) {
    int cost, mincost = 0;
    for (auto i: v) {
        if (root(i.second.first) != root(i.second.second)) {
            mincost += i.first;
            join(i.second.first, i.second.second); 
        }
    }
    return mincost;
}


// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    initialize();
    cin >> n >> e;
    int x, y, wt;
    for (int i=0; i<e; i++) {
        cin >> x >> y >> wt;
        v.push_back(make_pair(wt, make_pair(x, y)));
    }
    sort(v.begin(), v.end());
    int mincost = krushkal(v);
    cout << mincost << endl;

    
    
    return 0;
}
