#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    int source = 0, destination = nodes - 1;

    vector<int> adj[nodes];
    vector<int> indegree(nodes, 0);

    for (int e = 1; e <= edges; e++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        adj[--node1].push_back(--node2);
        indegree[node2]++;
    }

    vector<int> topo;
    vector<int> ways(nodes, 0);

    auto kahns_algorithm = [&]() -> void
    {
        queue<int> q;
        for (int i = 0; i < nodes; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        ways[source] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            topo.push_back(node);
            for (auto it : adj[node])
            {
                ways[it] = (ways[it] + ways[node]) % MOD;

                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
    };

    kahns_algorithm();
    cout << ways[destination];
}