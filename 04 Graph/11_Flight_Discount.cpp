#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LPINF LONG_LONG_MAX
#define vll vector<ll>
#define vvll vector<vll>
#define vp vector<pair<ll, ll>>
#define PQ_MIN priority_queue<vll, vvll, greater<vll>>

void dijkstra(vp adj[], vll &dist, int source)
{
    dist[source] = 0;

    PQ_MIN pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        ll cost = it[0], node = it[1];

        if(cost > dist[node]) continue;

        for (auto neighbourInfo : adj[node])
        {
            ll neighbourNode = neighbourInfo.first, costToReachAtNeighbourNode = neighbourInfo.second;

            if (dist[neighbourNode] > cost + costToReachAtNeighbourNode)
            {
                dist[neighbourNode] = costToReachAtNeighbourNode + cost;
                pq.push({dist[neighbourNode], neighbourNode});
            }
        }
    }
}

int main()
{
        int n, m;
    cin >> n >> m;
    vp adj[n], adjReverse[n];

    for (int i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v-- ;
        
        adj[u].push_back({v, w});
        adjReverse[v].push_back({u, w});
    }

    vll dist(n, 1e15), distReverse(n, 1e15);

    dijkstra(adj, dist, 0);
    dijkstra(adjReverse, distReverse, n-1);

    ll minimumDistance = 1e15 ;

    for(int node=0 ; node<n ; node++)
    {
        for(auto adjNodeInfo: adj[node])
        {
            int adjNode = adjNodeInfo.first ;
            ll adjWeight = adjNodeInfo.second ;

            ll distance = dist[node] + adjWeight/2 + distReverse[adjNode] ;
            minimumDistance = min(minimumDistance, distance) ;
        }
    }

    cout << minimumDistance ;
}