// Solve by applying DSU

#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

bool isvalid(int x, int n, int y, int m) {
    if (x >= 0 && x < n && y >= 0 && y < m) {
        return true;
    } else return false;
}

vector<int> solve(int n, int m, vector<pair<int,int>> operators) {
    vector<int> res;
    vector<vector<int>> grid(n, vector<int> (m, 0));
    int cnt = 0;
    for (int i=0; i<operators.size(); i++) {
        int found_near = 0;
        int x = operators[i].first;
        int y = operators[i].second;
        grid[x][y] = 1;
        for (int j=0; j<4; j++) {
            int newx = x + dx[j];
            int newy = y + dy[j];
            if (isvalid(newx, n, newy, m)) {
                if (grid[newx][newy] == 1) {
                    found_near++;
                }
            }
        }
        if (found_near == 0) {
            cnt++;
        }
        res.push_back(cnt);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // input 
    // int n = 4; int m = 5; vector<pair<int,int>> operators = {{1,1},{0,1},{3,3},{3,4}};
    // int n = 3; int m = 3; vector<pair<int,int>> operators = {{0,0},{0,1},{2,2},{2,1}};
    int n = 2; int m = 2; vector<pair<int,int>> operators = {{0,0},{1,1},{1,0},{0,1}};
    
    // solution 
    vector<int> res = solve(n, m, operators);
    for (int i: res)
        cout << i << " ";
    
    return 0;
}
