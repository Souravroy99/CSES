#include <bits/stdc++.h>
using namespace std;

bool dfs_topological_sort(vector<int>adj[], vector<bool>&vis, vector<bool>&pathVis, stack<int>&stk, int node)
{
    vis[node] = true ;
    pathVis[node] = true ;

    for(auto neighbour: adj[node])
    {
        if(!vis[neighbour]) {
            if(dfs_topological_sort(adj, vis, pathVis, stk, neighbour)) return true ;
        }
        else {
            if(pathVis[neighbour]) return true ;
        }
    }

    pathVis[node] = false ;
    stk.push(node) ;
    return false ;
}

int main()
{
    int nodes, edges ;
    cin >> nodes >> edges ;
    vector<int>adj[nodes] ;

    for(int e=1 ; e<=edges ; e++) {
        int node1, node2 ;
        cin >> node1 >> node2 ;

        adj[--node1].push_back(--node2) ;
    }

    vector<bool>vis(nodes, false), pathVis(nodes, false) ;
    stack<int>stk ;

    for(int node=0; node<nodes ; node++)
    {
        if(!vis[node]) {
            dfs_topological_sort(adj, vis, pathVis, stk, node) ;
        }
    }

    if(stk.size() != nodes) {
        cout << "IMPOSSIBLE\n" ;
    }
    else {
        vector<int>bookOrder ;
        while(!stk.empty())
        {
            bookOrder.push_back(stk.top()) ;
            stk.pop() ;
        }

        for(auto book : bookOrder) {
            cout << ++book << " " ;
        }
    }
}