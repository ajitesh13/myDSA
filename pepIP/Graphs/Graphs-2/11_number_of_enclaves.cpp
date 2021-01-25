#include <bits/stdc++.h>
using namespace std;

int n, m;
    void bfs(vector<vector<int>>& A, int i, int j) {
        if (A[i][j]) {
            A[i][j] = 0;
            if (i == 0 && j == 0) {
                bfs(A, i+1, j);
                bfs(A, i, j+1);
            } else if (i == 0 && j > 0 && j < m-1) {
                bfs(A, i+1, j);
                bfs(A, i, j+1);
                bfs(A, i, j-1);
            } else if (i == 0 && j == m-1) {
                bfs(A, i, j-1);
                bfs(A, i+1, j);
            } else if (i == n-1 && j == 0) {
                bfs(A, i-1, j);
                bfs(A, i, j+1);
            } else if (i == n-1 && j > 0 && j < m-1) {
                bfs(A, i-1, j);
                bfs(A, i, j+1);
                bfs(A, i, j-1);
            } else if (i == n-1 && j == m-1) {
                bfs(A, i-1, j);
                bfs(A, i, j-1);
            } else if (j == 0 && i > 0 && j < n-1) {
                bfs(A, i-1, j);
                bfs(A, i, j+1);
                bfs(A, i+1, j);
            } else if (j == m-1 && i > 0 && i < n-1) {
                bfs(A, i-1, j);
                bfs(A, i, j-1);
                bfs(A, i+1, j);
            }  else {
                bfs(A, i+1, j);
                bfs(A, i, j+1);
                bfs(A, i-1, j);
                bfs(A, i, j-1);
            }

        }
    }
    int numEnclaves(vector<vector<int>>& A) {
        n = A.size();
        m = A[0].size();
        for (int i=0; i<n; i++) {
            if (A[i][0]) {
                bfs(A, i, 0);
            } 
            if (A[i][m-1]) {
                bfs(A, i, m-1);
            }     
        }
        for (int j=0; j<m; j++) {
            if (A[0][j]) {
                bfs(A, 0, j);
            } 
            if (A[n-1][j]) {
                bfs(A, n-1, j);
            }
        }
        int res = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (A[i][j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> v = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout << numEnclaves(v) << '\n';
    
    return 0;
}
