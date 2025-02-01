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

    // In Binary Lifting, we can change loop's position  
    for(int child=1 ; child<n ; child++)
    {
        for(int level=1 ; level<=LOG ; level++)
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

    for (int child = 1; child < n; child++)
    {
        int parent ;
        cin >> parent ;
        --parent ; 

        up[child][0] = parent ;

        adj[parent].push_back(child) ;        
    }

    int startNode = 0 ;
    dfs_for_depth(adj, startNode) ;
    binary_lifting(up , n) ;

    vector<int>lca ;
    while(queries--)
    {
        int node1, node2 ;
        cin >> node1 >> node2 ;
        node1--, node2-- ;

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

        if(node1 != node2)
            lca.push_back(LCA) ;
        else 
            lca.push_back(node1) ;
    }

    for(auto l: lca) cout << ++l << "\n" ;
}