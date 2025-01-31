#include <bits/stdc++.h>
using namespace std;

const int N = 200001 ;
int depth[N] ;
 
int level_up(vector<vector<int>>&up, int node, int level)
{
    while(level != 0 && node != -1)
    {   
        int first_bit = log2(level) ;
        node = up[node][first_bit] ;
        level ^= (1<<first_bit) ;
    }

    return node ;
}

void binary_lifting(vector<vector<int>>&up, int n)
{
    int LOG = log2(n) ;

    for(int level=1 ; level<=LOG ; level++)
    {
        for(int child=1 ; child<n ; child++)
        {
            if(up[child][level-1] == -1) continue;
            up[child][level] = up[up[child][level-1]][level-1] ;
        }
    }
}

void dfs_for_depth(vector<int>adj[], int node, int parent=-1, int d=0)
{
    depth[node] = d ;
    for(auto neighbour: adj[node]) {
        if(neighbour == parent) continue;
        dfs_for_depth(adj, neighbour, node, d+1) ;
    }
}

int main()
{
    int n, queries;
    cin >> n >> queries;
    
    int LOG = log2(n);
    vector<vector<int>>up(n, vector<int>(LOG+1, -1)) ;

    vector<int>adj[n] ;

    for (int edge = 1; edge < n; edge++)
    {
        int node1, node2 ;
        cin >> node1 >> node2 ;
        --node1, --node2 ; 

        up[node2][0] = node1 ;

        adj[node1].push_back(node2) ;        
        adj[node2].push_back(node1) ;        
    }

    int startNode = 0 ;
    dfs_for_depth(adj, startNode) ;
    binary_lifting(up , n) ;

    vector<int>distance_between_nodes ;

    while(queries--)
    {
        int node1, node2 ;
        cin >> node1 >> node2 ;
        node1--, node2-- ;

        int temp_node1 = node1 ;
        int temp_node2 = node2 ;

        int depth_diff = abs(depth[node1] - depth[node2]) ;

        if(depth[node1] > depth[node2]) {
            node1 = level_up(up, node1, depth_diff) ;
        }
        if(depth[node1] < depth[node2]) {
            node2 = level_up(up, node2, depth_diff) ;
        }


        int level = LOG ; 
        while(level >= 0)
        {
            if(up[node1][level] != up[node2][level])
            {
                node1 = up[node1][level] ;
                node2 = up[node2][level] ;
            }

            level-- ;
        }

        int LCA = up[node1][0] ;

        if(node1 == node2) LCA = node1 ;

        // int dist = depth[temp_node1] + depth[temp_node2] - 2*depth[LCA] ;
        // distance_between_nodes.push_back(dist) ;
    }

    for(auto d: distance_between_nodes) 
    cout << d << "\n" ;
}