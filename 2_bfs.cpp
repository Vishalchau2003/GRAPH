
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 vector<int> bfsOfGraph(int V,vector<vector<int>>& adj) {

        vector<int> bfs;
        vector<int> vis(V, 0);

        queue<int> q;

        // start from node 0
        q.push(0);
        vis[0] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            bfs.push_back(node);

            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return bfs;
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

    vector<int>bfs= bfsOfGraph(n,adj);
    return 0;
}


