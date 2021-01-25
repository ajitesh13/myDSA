#include <bits/stdc++.h>
using namespace std;

int res, m, n;
void dfs(vector<vector<char>>& grid, int i, int j) {
    if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1') {
        grid[i][j] = '0';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
}

int numIslands(vector<vector<char>>& grid) {
    n = grid.size();
    m = grid[0].size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] == '1') {
                dfs(grid, i, j);
                res++;
            }
        }
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<char>> grid = {{'1', '1', '0'}, {'0', '0', '0'}, {'1', '0', '1'}};
    cout << numIslands(grid) << '\n';
    
    return 0;
}
