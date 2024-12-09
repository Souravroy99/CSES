#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> dist(n, vector<long long>(n, LONG_LONG_MAX));

    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;

        dist[u][v] = min(dist[u][v], (long long)c);
        dist[v][u] = min(dist[v][u], (long long)c);
    }

    auto floyd_warshall_algorithm = [&]() -> void
    {
        for (int u = 0; u < n; u++)
        {
            dist[u][u] = 0;
        }

        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][via] != LONG_LONG_MAX && dist[via][j] != LONG_LONG_MAX)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
    };

    floyd_warshall_algorithm();

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        long long distance = dist[--u][--v] == LONG_LONG_MAX ? -1 : dist[u][v];

        cout << distance << "\n";
    }
}