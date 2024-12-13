#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    int source = 0, destination = nodes - 1;

    vector<int> adj[nodes];
    vector<int> inorder(nodes, 0);

    for (int e = 1; e <= edges; e++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        adj[--node1].push_back(--node2);
        inorder[node2]++;
    }

    vector<int> topo;
    auto kahns_algorithm = [&]() -> vector<int>
    {
        queue<int> q;
        for (int i = 0; i < nodes; i++)
        {
            if (inorder[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto neighbour : adj[node])
            {
                inorder[neighbour]--;

                if (inorder[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        return topo;
    };

    kahns_algorithm();

    vector<int> parent(nodes, -1);
    vector<int> dist(nodes, INT_MIN);
    dist[source] = 0;

    for (int parent_city : topo)
    {
        if (dist[parent_city] == INT_MIN)
            continue;

        for (auto node : adj[parent_city])
        {
            if (dist[node] < 1 + dist[parent_city])
            {
                parent[node] = parent_city;
                dist[node] = 1 + dist[parent_city];
            }
        }
    }

    if (dist[destination] == INT_MIN)
    {
        cout << "IMPOSSIBLE";
        exit(0);
    }

    vector<int> path;
    for (int city = destination; city != -1; city = parent[city]) {
        path.push_back(city);
    }

    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    for (auto city : path)
    {
        cout << ++city << " ";
    }
}