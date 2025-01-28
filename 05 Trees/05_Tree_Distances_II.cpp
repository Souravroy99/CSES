#include<bits/stdc++.h>
using namespace std ;

const int N = 200001 ;
long long dist[N];
int nodes[N];

void dfs(vector<int>adj[], int node, int parent)
{
    nodes[node]++ ;

    for(auto child: adj[node])
    {
        if(child == parent) continue;
        dfs(adj, child, node) ;

        dist[node] += nodes[child]+dist[child] ;
        nodes[node] += nodes[child] ;
    }
}

void dfs2(vector<int>adj[], int node, int parent, int n)
{
    for(auto child: adj[node])
    {
        if(child == parent) continue;

        int num_of_node = n - nodes[child] ;
        long long tot_dist = dist[node] - (dist[child] + nodes[child]) ;

        dist[child] += num_of_node + tot_dist ;

        dfs2(adj, child, node, n) ;
    }
}

int main()
{
    int n ;
    cin >> n ;
    vector<int>adj[n+1] ;
    for(int i=0 ; i<n-1 ; i++) {
        int u, v;
        cin >> u >> v ;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int startNode = 1 ;
    dfs(adj, startNode, -1) ;
    dfs2(adj, startNode, -1, n) ;

    for(int i=1 ; i<=n ; i++) cout << dist[i] << " " ;
}