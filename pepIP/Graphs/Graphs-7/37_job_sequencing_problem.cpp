#include <bits/stdc++.h>
using namespace std;
vector<int> deadlines;

int node_find(int x) {
    if (x == deadlines[x]) {
        return x;
    }
    int temp = node_find(deadlines[x]);
    deadlines[x] = temp;
    return temp;
}

void node_union(int x, int y) {
    int px = node_find(x);
    int py = node_find(y);
    deadlines[px] = py;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<int,pair<char,int>>> v;
    int mx = INT32_MIN;
    for (int i=0; i<n; i++) {
        char ch;
        int b, c;
        cin >> ch >> b >> c;
        v.push_back({c, {ch, b}});
        mx = max(mx, b);
    }
    sort(v.rbegin(), v.rend());
    deadlines.assign(mx+1, 0);
    for (int i=0; i<deadlines.size(); i++) {
        deadlines[i] = i;
    }
    vector<pair<int,char>> ans;
    for (int i=0; i<n; i++) {
        int node = v[i].second.second;
        int px = node_find(deadlines[node]);
        if (px > 0) {
            node_union(px, px-1);
            ans.push_back({v[i].second.second, v[i].second.first});
        }
        
    }
    sort(ans.begin(), ans.end());
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i].second << ' ';
    }
    cout << endl;
    
    return 0;
}
