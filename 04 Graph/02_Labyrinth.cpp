#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LPINF LONG_LONG_MAX
#define LNINF LONG_LONG_MIN
#define PINF INT_MAX
#define NINF INT_MIN
#define MOD 1000000007
#define DMOD 998244353
#define vll vector<ll>
#define vvll vector<vll>
#define vcc vector<char>
#define vvcc vector<vcc>
#define vbl vector<bool>
#define vvbl vector<vbl>
#define pb push_back
#define pr pair<ll, ll>
#define vp vector<pair<ll, ll>>
#define vs vector<string>
#define fr(i, a, n) for (ll i = a; i < n; i++)
#define rfr(i, n, a) for (ll i = n; i >= a; i--)
#define TAKE(arr, n)            \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define PTAKE(arr, n)           \
    for (int i = 0; i < n; i++) \
    cin >> arr[i].first >> arr[i].second
#define ALL(arr) (arr).begin(), (arr).end()
#define SORTA(arr, n) sort(arr, arr + n)
#define SORT(arr) sort(arr.begin(), arr.end())
#define RSORT(arr) sort(arr.rbegin(), arr.rend())
#define SUM(arr) accumulate(arr.begin(), arr.end(), 0LL)
#define MAX(arr) *max_element(begin(arr), end(arr))
#define MIN(arr) *min_element(begin(arr), end(arr))
#define MAP map<ll, ll>
#define UMAP unordered_map<ll, ll>
#define MMAP multimap<ll, ll>
#define ST set<ll>
#define UST unordered_set<ll>
#define MST multiset<ll>
#define PQ_MAX priority_queue<ll>
#define PQ_MIN priority_queue<ll, vll, greater<ll>>
#define pn cout << "NO" << "\n"
#define py cout << "YES" << '\n'
#define pmo cout << -1
#define imp cout << -1
#define nl cout << '\n'

bool isValid(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dijkstra(vvcc &mat, int startX, int startY)
{
    int n = mat.size(), m = mat[0].size();
    int endX = -1, endY = -1;

    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> q;

    q.push({startX, startY});

    int xArr[] = {-1, 0, +1, 0};
    int yArr[] = {0, +1, 0, -1};
    string dir = "URDL";

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (mat[row][col] == 'B')
        {
            endX = row;
            endY = col;
            break;
        }

        for (int idx = 0; idx < 4; idx++)
        {
            int dx = row + xArr[idx];
            int dy = col + yArr[idx];

            if (isValid(dx, dy, n, m) && parent[dx][dy] == pair<int, int>{-1, -1} && mat[dx][dy] != '#')
            {
                parent[dx][dy] = {row, col};
                q.push({dx, dy});
            }
        }
    }

    if (endX == -1 || endY == -1)
    {
        cout << "NO";
        return;
    }

    string path = "";

    while(endX != startX || endY != startY)
    {
        int dx = parent[endX][endY].first, dy = parent[endX][endY].second ; 

        for(int idx=0 ; idx<4 ; idx++)
        {
            if(dx+xArr[idx] == endX && dy+yArr[idx] == endY)
            {
                path.push_back(dir[idx]) ;
                break;
            }
        }

        endX = dx ;
        endY = dy ;
    }

    reverse(ALL(path));
    py ;
    cout << path.length() << endl ;
    cout << path << endl ;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vvcc mat(n, vcc(m));

    fr(i, 0, n) fr(j, 0, m) cin >> mat[i][j];

    fr(i, 0, n)
    {
        fr(j, 0, m)
        {
            if (mat[i][j] == 'A')
            {
                dijkstra(mat, i, j);
                goto jump;
            }
        }
    }
jump:;
}