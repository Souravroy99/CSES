#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int>adj[], vector<int>&bossOf, int node)
{
    int numberOfEmployee = 1;
    for (auto child : adj[node]) {
        numberOfEmployee += dfs(adj, bossOf, child) ;
    }

    return bossOf[node] = numberOfEmployee ;
}

int main()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    for (int i = 2; i <= n; i++)
    {
        int parent;
        cin >> parent;

        adj[--parent].push_back(i-1);
    }

    vector<int> bossOf(n, 0);

    dfs(adj, bossOf, 0) ;

    for (auto it : bossOf) {
        cout << --it << " ";
    }
}