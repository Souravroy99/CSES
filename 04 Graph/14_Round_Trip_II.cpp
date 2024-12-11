#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], vector<bool> &vis, vector<bool> &pathVis, vector<int> &parent, int node, int &start, int &end)
{
    vis[node] = true;
    pathVis[node] = true ;

    for (auto neighbour : adj[node])
    {
        if (vis[neighbour] == false)
        {
            parent[neighbour] = node;
            if (dfs(adj, vis, pathVis, parent, neighbour, start, end))
                return true;
        }
        else if (pathVis[neighbour])
        {
            start = node;
            end = neighbour;
            return true;
        }
    }

    pathVis[node] = false ;
    return false;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> adj[nodes + 1];
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> vis(nodes + 1, false);
    vector<bool> pathVis(nodes + 1, false);
    vector<int> parent(nodes + 1, -1);
    int start = -1, end = -1;

    for (int node = 1; node <= nodes; node++)
    {
        if (!vis[node])
        {
            if (dfs(adj, vis, pathVis, parent, node, start, end))
                break;
        }
    }

    if (start == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        vector<int> path;

        path.push_back(end);
        for (int node = start; node != end; node = parent[node])
        {
            path.push_back(node);
        }
        path.push_back(end);

        int sz = path.size();
        cout << sz << endl;
        
        for (int i = sz - 1; ~i; --i) {
            cout << path[i] << " ";
        }
    }
}