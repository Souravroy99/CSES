#include <bits/stdc++.h>
using namespace std;

int cnt=0 ;

int dfs(vector<int>adj[], vector<bool>&vis, int node, int parent=-1)
{
    for(auto it : adj[node])
    {
        if(it == parent) continue;

        if(!vis[it])
        {
            int res = dfs(adj, vis, it, node) ;

            if(res == 1) 
            {
                cnt += !vis[node] ;
                vis[node] = true ;
            }
        }
    }

    if(!vis[node])
        return vis[node] = true ;
    return false ;
}

int main()
{
    int n;
    cin >> n;
    vector<int> adj[n+1];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>vis(n+1,0);
    dfs(adj, vis, 1) ;
    cout << cnt ;
}