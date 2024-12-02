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

int main()
{
    int n, m;
    cin >> n >> m;
    vll adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[--u].pb(--v);
        adj[v].pb(u);
    }

    vector<int> pupil(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (pupil[i] == -1)
        {
            queue<pair<int, int>> q;
            q.push({i, 1});

            while (!q.empty())
            {
                auto it = q.front();
                q.pop();

                int node = it.first;
                int team = it.second;

                for (auto neighbour : adj[node])
                {
                    if (pupil[neighbour] == -1)
                    {
                        pupil[neighbour] = 3 - team;
                        q.push({neighbour, pupil[neighbour]});
                    }
                    else if (pupil[neighbour] == team)
                    {
                        cout << "IMPOSSIBLE";
                        goto jump;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int team = pupil[i] == -1 ? 1 : pupil[i] ;
        cout << team << " ";
    }

jump:;
}