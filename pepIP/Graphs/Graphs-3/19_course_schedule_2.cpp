#include <bits/stdc++.h>
using namespace std;

vector<int> res;
vector<vector<int>> adj;
vector<int> indegree;
    
void kahn() {
    queue<int> q;
    for (int i=0; i<adj.size(); i++) {
        for (int j=0; j<adj[i].size(); j++) {
            indegree[adj[i][j]]++;
        }
    }
    for (int i=0; i<indegree.size(); i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int rem = q.front();
        q.pop();
        res.push_back(rem);
        for (int i=0; i<adj[rem].size(); i++) {
            if (indegree[adj[rem][i]]) {
                indegree[adj[rem][i]]--;
                if (indegree[adj[rem][i]] == 0) {
                    q.push(adj[rem][i]);
                }
            }
        }
    }
}
    
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    adj.assign(numCourses, vector<int> ());
    indegree.assign(numCourses, 0);
    for (int i=0; i<prerequisites.size(); i++) {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    kahn();
    if (res.size() == numCourses) {
        return res;
    } else {
        res.clear();
        return res;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    int numCourses = 4;
    vector<int> res = findOrder(numCourses, prerequisites);
    for (int i=0; i<res.size(); i++) {
        cout << res[i] << ' ';
    }
    
    return 0;
}
