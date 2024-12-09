#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define vcc vector<char>
#define vvbl vector<vbl>
#define pb push_back
#define pr pair<ll, ll>
#define fr(i, a, n) for (ll i = a; i < n; i++)
#define nl cout << '\n'

int xArr[] = {-1, 0, +1, 0};
int yArr[] = {0, +1, 0, -1};
string dir = "URDL";

bool isValid(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void multi_source_bfs(vector<vector<char>> &grid, int n, int m)
{
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<vector<int>> q;

    int startX = -1, startY = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'M')
            {
                q.push({0, i, j});
                dist[i][j] = 0;
            }
            if (grid[i][j] == 'A')
            {
                startX = i;
                startY = j;
            }
        }
    }

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int distance = it[0], row = it[1], col = it[2];

        for (int idx = 0; idx < 4; idx++)
        {
            int dx = row + xArr[idx];
            int dy = col + yArr[idx];

            if (isValid(dx, dy, n, m) && grid[dx][dy] != '#' && dist[dx][dy] > 1 + distance)
            {
                dist[dx][dy] = 1 + distance;
                q.push({dist[dx][dy], dx, dy});
            }
        }
    }

    q.push({0, startX, startY});
    int endX = -1, endY = -1;

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int distance = it[0], row = it[1], col = it[2];
        if (row == 0 || row == n - 1 || col == 0 || col == m - 1)
        {
            endX = row;
            endY = col;
            break;
        }

        for (int idx = 0; idx < 4; idx++)
        {
            int dx = row + xArr[idx];
            int dy = col + yArr[idx];

            if (isValid(dx, dy, n, m) && grid[dx][dy] == '.' && dist[dx][dy] > 1 + distance)
            {
                parent[dx][dy] = {row, col};
                dist[dx][dy] = 1 + distance;
                q.push({dist[dx][dy], dx, dy});
            }
        }
    }
    if (endX == -1)
    {
        cout << "NO";
        return;
    }

    string path;
    while (endX != startX || endY != startY)
    {
        int parent_X = parent[endX][endY].first;
        int parent_Y = parent[endX][endY].second;

        for (int idx = 0; idx < 4; idx++)
        {
            if (parent_X + xArr[idx] == endX && parent_Y + yArr[idx] == endY)
            {
                path.push_back(dir[idx]);
                break;
            }
        }

        endX = parent_X;
        endY = parent_Y;
    }
    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.length() << "\n";
    cout << path;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    multi_source_bfs(grid, n, m);
}