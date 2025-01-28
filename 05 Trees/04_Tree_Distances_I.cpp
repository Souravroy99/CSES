#include<bits/stdc++.h>
using namespace std ;

const int N = 200001 ;
int firstMax[N] ;
int secondMax[N] ;
int firstMax_via_child[N] ;


void dfs(vector<int>adj[], int node, int parent)
{
    for(auto child: adj[node])
    {
        if(child == parent) continue ;

        dfs(adj, child, node) ;

        if(firstMax[child]+1 > firstMax[node])
        {
            secondMax[node] = firstMax[node] ;
            firstMax[node] = 1+firstMax[child] ;
            firstMax_via_child[node] = child ;
        }
        else if(firstMax[child]+1 > secondMax[node])
        {
            secondMax[node] = 1+firstMax[child] ;
        }
    }
}

void dfs2(vector<int>adj[], int node, int parent)
{
    for(auto child: adj[node])    
    {
        if(child == parent) continue;

        int distance_from_parent = firstMax[node] ;
        if(firstMax_via_child[node] == child) distance_from_parent = secondMax[node] ;
        
        if(distance_from_parent+1 >= firstMax[child])
        {   
            firstMax_via_child[child] = -1 ;
            firstMax[child] = distance_from_parent+1 ;
        }
        else if(distance_from_parent+1 >= secondMax[child])
        {
            secondMax[child] = distance_from_parent+1 ;
        }

        dfs2(adj, child, node) ;
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
    dfs2(adj, startNode, -1) ;

    for(int i=1 ; i<=n ; i++) cout << firstMax[i] << " " ;
}