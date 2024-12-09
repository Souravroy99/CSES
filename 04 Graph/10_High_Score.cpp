#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vvll vector<vector<ll>>

void Bellman_Ford(vvll &edges, vector<bool> &vis, vector<bool> &visReverse, int n)
{
    vector<ll> dist(n + 1, LONG_LONG_MIN);
    dist[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (auto it : edges)
        {
            ll u = it[0], v = it[1], w = it[2];
            if (dist[u] != LONG_LONG_MIN && dist[v] < w + dist[u])
            {
                dist[v] = w + dist[u];

                if (i == n && vis[v] && visReverse[v])
                {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }

    cout << dist[n - 1] << endl;
}

void dfs(int node, vector<bool> &vis, vector<int> adj[])
{
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vvll edges;
    vector<int> adj[n], adjReverse[n];

    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;

        edges.push_back({--u, --v, w});
        adj[u].push_back(v);
        adjReverse[v].push_back(u);
    }

    vector<bool> vis(n, false), visReverse(n, false);

    dfs(0, vis, adj);
    dfs(n - 1, visReverse, adjReverse);

    Bellman_Ford(edges, vis, visReverse, n);
}