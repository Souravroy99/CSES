#include <bits/stdc++.h>
using namespace std;

void sparse_table(int n, vector<pair<int,int>>&arr, vector<vector<pair<int,int>>>&sparseTable)
{
    int LOG = log2(n) ;
    for(int i=0 ; i<n ; i++) {
        sparseTable[i][0] = arr[i] ;
    }

    for(int level=1 ; level<=LOG ; level++)
    {
        for(int i=0 ; i + (1<<level) <= n ; i++)
        {
            sparseTable[i][level] = min(sparseTable[i][level-1], sparseTable[i + (1<<(level-1))][level-1]) ;
        }
    }
}

void euler_tour(vector<int>adj[], vector<int>&firstOcc, vector<int>&eulerTour, vector<int>&depth, int node, int parent, int d)
{
    firstOcc[node] = eulerTour.size() ;
    eulerTour.push_back(node) ;
    depth.push_back(d) ;

    for(auto neighbour: adj[node])
    {
        if(neighbour == parent) continue ;
        euler_tour(adj, firstOcc, eulerTour, depth, neighbour, node, d+1) ;

        eulerTour.push_back(node) ;
        depth.push_back(d) ;
    }
}

int main()
{
    int n, queries ;
    cin >> n >> queries ;
    vector<int>adj[n] ;

    for(int i=1 ; i<n ; i++) {
        int node1, node2 ;
        cin >> node1 >> node2 ;
        node1--, node2-- ;
        adj[node1].push_back(node2) ;
        adj[node2].push_back(node1) ;
    }

    vector<int>firstOcc(n, -1) ;
    vector<int>eulerTour, depth ;

    euler_tour(adj, firstOcc, eulerTour, depth, 0, -1, 0) ; // Normal DFS


    int m = depth.size(), LOG = log2(m) ;
    vector<vector<pair<int,int>>>sparseTable(m, vector<pair<int,int>>(LOG+1)) ;
    vector<pair<int,int>>depthIdx ;

    for(int i=0 ; i<2*n ; i++) depthIdx.push_back({depth[i], i}) ;

    sparse_table(m, depthIdx, sparseTable) ;


    while(queries--)
    {
        int node1, node2 ;
        cin >> node1 >> node2 ;
        node1--, node2-- ;

        int idx1 = firstOcc[node1], idx2 = firstOcc[node2] ;
        if(idx1 > idx2) swap(idx1, idx2) ;

        int len = idx2-idx1+1 ;
        int j = log2(len) ;
 
        pair<int,int> minDepth = min(sparseTable[idx1][j], sparseTable[idx2 - (1<<j) + 1][j]) ; 

        int lcaIdx = minDepth.second ;
        int lcaNode = eulerTour[lcaIdx] ;

        cout << depth[idx1] + depth[idx2] - 2*depth[firstOcc[lcaNode]] << endl ;
    }
}