#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,m;
    cin>>n >> m ;
    vector<vector<pair<int,int>>>adj(n) ;

    for(int i=1 ; i<=m ; i++)
    {
        int u, v, c;
        cin >> u >> v >> c ;
        adj[--u].push_back({--v,c}) ;
    }

    set<pair<long long, int>>minHeap ;
    vector<long long>dist(n, LONG_LONG_MAX) ;

    int start = 0 ;

    minHeap.insert({0, start}) ;
    dist[start] = 0;

    while(!minHeap.empty())
    {
        auto it = minHeap.begin() ;
        long long cost = (*it).first ;
        int node = (*it).second ;
        minHeap.erase(it) ;

        for(auto neighbourInfo: adj[node])
        {
            int neighbourNode = neighbourInfo.first ;
            int costToReach = neighbourInfo.second ;

            if(dist[neighbourNode] > costToReach+cost)
            {
                if(dist[neighbourNode] != LONG_LONG_MAX) {
                    minHeap.erase({dist[neighbourNode], neighbourNode}) ;
                }

                dist[neighbourNode] = costToReach + cost ;
                minHeap.insert({dist[neighbourNode], neighbourNode}) ;
            }
        }

    }

    for(auto it : dist) {
        cout << it << " " ;
    }
}