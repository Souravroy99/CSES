#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define INF LONG_LONG_MAX
#define NINF LONG_LONG_MIN

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<pair<int, ll>> adj[nodes];

    for (int i = 1; i <= edges; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[--u].push_back({--v, w});
    }

    stack<ll> stk;
    vector<int> topo_order;
    vector<bool> vis(nodes), pathVis(nodes);

    function<bool(int)> dfs = [&](int node) -> bool
    {
        vis[node] = pathVis[node] = true;
        for (auto it : adj[node])
        {
            if (!vis[it.first])
            {
                if (dfs(it.first))
                {
                    return true;
                }
            }
            else if (pathVis[it.first])
            {
                return true;
            }
        }
        stk.push(node);
        return pathVis[node] = false;
    };
    dfs(0);

    vector<ll> dist(nodes, INF);
    dist[0] = 0;

    while (!stk.empty())
    {
        topo_order.push_back(stk.top());
        stk.pop();

        cout << topo_order.back() << " " ;
    }
    cout<<endl ;

    for (auto parent : topo_order)
    {
        if (dist[parent] == INF)
            continue;

        for (auto child : adj[parent])
        {
            int childNode = child.first ;
            ll edgeWeight = child.second ;

            if (dist[childNode] > edgeWeight + dist[parent])
            {
                dist[childNode] = edgeWeight + dist[parent];
            }
        }
    }

    ll minimum_price = dist[nodes - 1];

    vector<ll> ways(nodes, 0), maxFlightCnt(nodes, 0);
    ways[0] = 1;

    dist.resize(nodes, INF);
    dist[0] = 0;

    int minFlightCnt = -1;

    for (auto parent : topo_order)
    {
        if (dist[parent] == INF)
            continue;

        for (auto child : adj[parent])
        {
            int childNode = child.first;
            ll edgeWeight = child.second;

            if (dist[childNode] > edgeWeight + dist[parent])
            {
                dist[childNode] = edgeWeight + dist[parent];
            }

            if (dist[parent]+edgeWeight <= minimum_price)
            {
                // cout << childNode << " " << parent << endl ;

                ways[childNode] = (ways[parent] + ways[childNode]) % MOD;
                maxFlightCnt[childNode] = (maxFlightCnt[parent] + 1) % MOD;

                if (minFlightCnt == -1 && childNode == nodes - 1)
                    minFlightCnt = maxFlightCnt[childNode];
            }
        }
    }

    cout << minimum_price << " " << ways[nodes - 1] << " " << minFlightCnt << " " << maxFlightCnt[nodes - 1] << endl;
}