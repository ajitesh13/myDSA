#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj1;
    stack<int> st;
    unordered_set<int> st1;
    vector<bool> visit;
    
    void dfs1(int s) {
        if (!visit[s]) {
            visit[s] = true;
            for (int i: adj1[s]) {
                dfs1(i);
            }
            st.push(s);
        }
    }
    
    void dfs(int s) {
        if (!visit[s]) {
            visit[s] = true;
            st1.insert(s);
            for (int i: adj1[s]) {
                dfs(i);
            }
        }
    }
    
	int findMotherVertex(int V, vector<int>adj[]){
	    for (int i=0; i<V; i++) {
	        adj1.push_back(adj[i]);
	    }    
	    visit.assign(V, false);
	    dfs1(0);
	    int ans = st.top();
	    visit.assign(V, false);
	    dfs(ans);
	    if (st1.size() == V) {
	        return ans;
	    } else {
	        return -1;
	    }
	}

};



int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  