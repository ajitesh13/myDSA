#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    int n = graph.size();
    queue<int> q;
    vector<int> visited(n, 0);
    int cnt = 0;
    q.push(0);
    visited[0] = -5;
    for (int i=1; i<n; i++) {
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            for (int j=0; j<graph[top].size(); j++) {
                if (visited[graph[top][j]] == 0) {
                    if (visited[top] == -5) {
                        visited[graph[top][j]] = -3;
                    } else {
                        visited[graph[top][j]] = -5;
                    }
                    q.push(graph[top][j]);
                } else if (visited[graph[top][j]] == visited[top]) {
                    cnt++;
                    break;
                } 
            }
        }
        q.push(i);
    }
    
    if (cnt == 0) {
        cout <<  true << '\n';
    } else {
        cout <<  false << '\n'; 
    }
    
    return 0;
}
