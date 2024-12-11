#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define LPINF 1e15

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;

    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, --v ;

        edges.push_back({u, v, w});
    }

    vector<ll> dist(n, LPINF), parent(n, -1);
    dist[0] = 0;

    bool isNegativeCyclePresent = false;
    int start = -1;

    for (int iter = 1; iter <= n; iter++)
    {
        for (auto edge_info : edges)
        {
            int u = edge_info[0], v = edge_info[1];
            ll edgeWeight = edge_info[2];

            if (dist[v] > edgeWeight + dist[u])
            {
                dist[v] = edgeWeight + dist[u];
                parent[v] = u;

                if (iter == n)
                {
                    isNegativeCyclePresent = true;
                    start = u;
                    break;
                }
            }
        }
    }

    if (isNegativeCyclePresent)
    {
        cout << "YES\n";

        // Initially, the start may not point inside a cycle, but this iteration ensures that the start will be placed inside the cycle.
        for (int i = 0; i < n; i++)     // In this question this is the main concept
        {
            start = parent[start];
        }

        vector<int> path;
        path.push_back(start);

        for (int node = parent[start]; node != start; node = parent[node]) {
            path.push_back(node);
        }
        path.push_back(start);

        reverse(path.begin(), path.end());
        for (auto p : path) {
            cout << ++p << " ";
        }
    }
    else
    {
        cout << "NO\n";
    }
}