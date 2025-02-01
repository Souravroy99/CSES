#include <bits/stdc++.h>
using namespace std;

void sparse_table(int n, vector<vector<pair<int, int>>> &sparseTable, vector<pair<int, int>> &depth_idxs)
{
    int LOG = log2(n);
    for (int i = 0; i < n; i++)
    {
        sparseTable[i][0] = depth_idxs[i];
    }

    for (int level = 1; level <= LOG; level++)
    {
        for (int i = 0; i + (1 << level) <= n; i++)
        {
            sparseTable[i][level] = min(sparseTable[i][level - 1], sparseTable[i + (1 << (level - 1))][level - 1]);
        }
    }
}

void euler_tour(vector<int> adj[], vector<int> &firstOccurence, vector<int> &eulerTour, vector<int> &depth, int node, int parent, int dth)
{
    firstOccurence[node] = eulerTour.size();
    eulerTour.push_back(node);
    depth.push_back(dth);

    for (auto neighbour : adj[node])
    {
        if (neighbour == parent)
            continue;
        euler_tour(adj, firstOccurence, eulerTour, depth, neighbour, node, dth + 1);
        eulerTour.push_back(node);
        depth.push_back(dth);
    }
}

void dfs_with_binary_lifting(int node, int parent, vector<int>adj[], vector<vector<int>>&up, int n)
{
    int LOG = log2(n) ;
    up[node][0] = parent ;

    for(int level=1 ; level<=LOG ; level++)
    {
        if(up[node][level-1] != -1)
            up[node][level] = up[up[node][level-1]][level-1] ;
    }

    for(auto neighbour: adj[node])
    {
        if(neighbour == parent) continue;
        dfs_with_binary_lifting(neighbour, node, adj, up, n) ;
    }
}

long long dfs_sum_sweepLine(vector<long long>&sweepLine, vector<int>adj[], int node, int parent)
{
    long long totalSum = sweepLine[node] ;
    for(auto neighbour: adj[node])
    {
        if(neighbour == parent) continue;
        totalSum += dfs_sum_sweepLine(sweepLine, adj, neighbour, node) ;
    }

    return sweepLine[node] = totalSum ;
}

int main()
{
    int n, queries;
    cin >> n >> queries;

    int LOG = log2(n);
    vector<int> adj[n];


    for (int i = 1; i < n; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        node1--, node2--;

        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    vector<vector<int>>up(n, vector<int>(LOG + 1, -1)) ;
    dfs_with_binary_lifting(0, -1, adj, up, n) ;

    vector<int> firstOccurence(n, -1);
    vector<int> eulerTour, depth;

    euler_tour(adj, firstOccurence, eulerTour, depth, 0, -1, 0);

    int m = depth.size();
    vector<pair<int, int>> depth_idxs;

    for (int i = 0; i < m; i++)
    {
        depth_idxs.push_back({depth[i], i});
    }

    vector<vector<pair<int, int>>> sparseTable(m, vector<pair<int, int>>(log2(m) + 1)) ;
    sparse_table(m, sparseTable, depth_idxs);

    vector<long long> sweepLine(n, 0);
    while (queries--)
    {
        int node1, node2;
        cin >> node1 >> node2;
        node1--, node2--;

        int idx1 = firstOccurence[node1];
        int idx2 = firstOccurence[node2];
        if (idx1 > idx2)
            swap(idx1, idx2);

        int len = idx2 - idx1 + 1;
        int j = log2(len);
 
        int lcaIdx = min(sparseTable[idx1][j], sparseTable[idx2 - (1 << j) + 1][j]).second ;
        int LCA = eulerTour[lcaIdx] ;

        sweepLine[node1]++ ;
        sweepLine[node2]++ ;
        sweepLine[LCA]-- ;

        int parent_of_LCA = up[LCA][0] ;
        if(parent_of_LCA != -1) {
            sweepLine[parent_of_LCA]-- ;
        }
    }
 
    dfs_sum_sweepLine(sweepLine, adj, 0, -1) ;

    for(auto it : sweepLine) cout << it << " " ;
}