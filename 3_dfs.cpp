
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    
void dfs(int node, vector<vector<int>>& adj,
         vector<int>& vis, vector<int>& ans) {

    vis[node] = 1;
    ans.push_back(node);

    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis, ans);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<vector<int>>& adj) {

    vector<int> vis(V + 1, 0);   // because you used n+1 in main
    vector<int> ans;

    dfs(0, adj, vis, ans);       // start from node 0

    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);

    for(int i=0;i<m;i++){
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }

    vector<int>bfs= dfsOfGraph(n,adj);
    return 0;
}


