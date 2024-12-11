#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define LPINF 1e15
#define pr pair<ll, int>

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, ll>> adj[n];

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, --v;

        adj[u].push_back({v, w});
    }

    priority_queue<ll> dist[n];
    priority_queue<pr, vector<pr>, greater<pr>> pq; // Distance, Node

    dist[0].push(0);
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto nodeInfo = pq.top();
        pq.pop();

        ll costToReactParentNode = nodeInfo.first;
        int node = nodeInfo.second;

        if (costToReactParentNode > dist[node].top())
            continue;

        for (auto it : adj[node])
        {
            int neighbourNode = it.first;
            ll costToReachNeighbourNode = it.second;
            ll totalCost = costToReactParentNode + costToReachNeighbourNode;

            if ((int)dist[neighbourNode].size() < k)
            {
                dist[neighbourNode].push(totalCost);
                pq.push({totalCost, neighbourNode});
            }
            else if (dist[neighbourNode].top() > totalCost)
            {
                dist[neighbourNode].pop();
                dist[neighbourNode].push(totalCost);
                pq.push({totalCost, neighbourNode});
            }
        }
    }

    vector<ll>cost ;
    while(!dist[n-1].empty())
    {
        cost.push_back(dist[n-1].top());
        dist[n-1].pop() ;
    }
    reverse(cost.begin(), cost.end()) ;
    for(auto it : cost) {
        cout << it << ' ' ;
    }
}