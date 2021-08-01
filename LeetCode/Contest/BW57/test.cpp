/* [[18,19],[10,11],[21,22],[5,6],[2,3],[6,7],[43,44],[48,49],[53,54],[12,13],
[20,21],[34,35],[17,18],[1,2],[35,36],[16,17],[9,10],[14,15],[25,26],[37,38],
[30,31],[50,51],[22,23],[3,4],[27,28],[29,30],[33,34],[39,40],[49,50],[15,16],
[4,5],[46,47],[51,52],[32,33],[11,12],[28,29],[47,48],[36,37],[40,41],[42,43],
[52,53],[41,42],[31,32],[23,24],[8,9],[19,20],[24,25],[26,27],[45,46],[44,45],[7,8],[13,14],[38,39]]

8

Answer: 0 */

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,pair<int,char>> a, pair<int,pair<int,char>> b) {
    if (a.first < b.first) {
        return true;
    } else if (a.first == b.first) {
        if (a.second.second == 'l' and b.second.second == 's') {
            return true;
        } else return false;
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<pair<int,pair<int,char>>> v;
    v.push_back({52,{32,'l'}});
    v.push_back({52,{40,'s'}});
    v.push_back({53,{8,'s'}});
    v.push_back({53,{40,'l'}});
    v.push_back({54,{8,'l'}});
    sort(v.begin(), v.end(), cmp);

    for (auto i: v) {
        cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
    }
    return 0;
}
