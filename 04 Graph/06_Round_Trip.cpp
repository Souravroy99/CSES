#include<bits/stdc++.h>
using namespace std ;

void dfs(vector<int>adj[], vector<bool>&vis, vector<int>&parent, int node, int &start, int &end)
{
    vis[node] = true ;
    
    for(auto neighbour: adj[node])
    {
        if(vis[neighbour] == false)
        {
            parent[neighbour] = node;
            dfs(adj, vis, parent, neighbour, start, end) ;
            if(start != -1) return ;
        }
        else if(neighbour != parent[node])
        {
            start = node ;
            end = neighbour ;
            return ;
        }
    }
}


int main()
{
    int nodes, edges;
    cin >> nodes >> edges ;
    vector<int>adj[nodes+1] ;
    for(int i=0 ; i<edges ; i++) {
        int u, v ;
        cin >> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    vector<bool>vis(nodes+1, false) ;
    vector<int>parent(nodes+1, -1) ;
    int start=-1, end=-1 ;

    for(int node=1; node<=nodes; node++)
    {
        if(!vis[node])
        {
            dfs(adj, vis, parent, node, start, end) ;
            if(start != -1) break ;
        }
    }

    if(start == -1) {
        cout << "IMPOSSIBLE" ;
    }
    else {
        vector<int>path;
        
        path.push_back(end) ;
        for(int node = start ; node != end ; node = parent[node]) {
            path.push_back(node) ;
        }
        path.push_back(end) ;

        cout << path.size() << endl ;
        for(auto node: path) {
            cout << node << " " ;
        }
    }
}