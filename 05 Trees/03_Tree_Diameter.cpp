#include <bits/stdc++.h>
using namespace std;

pair<int,int>dfs(vector<int>adj[], vector<bool>&vis, int node, int parent=-1) // Height, Diameter
{
    int dia = 1 ;
    int maxHeight=0, h1=0, h2=0;

    for(auto it : adj[node])
    {
        if(it == parent) continue;

        if(!vis[it])
        {
            vis[it] = true ;
            auto res = dfs(adj, vis, it, node) ;

            maxHeight = max(maxHeight, res.first) ;
            dia = max(dia, res.second) ;

            if(res.first >= h1) {
                h2 = h1 ;
                h1 = res.first ;
            }
            else if(res.first > h2) {
                h2 = res.first;
            }
        }           
    }

    dia = max(dia, h1+1+h2) ;
    return {maxHeight+1, dia} ;
}

int main()
{
    int n;
    cin >> n;
    vector<int> adj[n+1];
    vector<bool>vis(n+1,0);

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << dfs(adj, vis, 1).second-1 ;
}