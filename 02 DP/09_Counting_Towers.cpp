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
#define pb push_back
#define pr pair<ll, ll>
#define vp vector<pair<ll, ll>>
#define vs vector<string>
#define fr(i, a, n) for (ll i = a; i < n; i++)
#define rfr(i, n, a) for (ll i = n; i >= a; i--)
#define TAKE(arr, n)            \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define ALL(arr) (arr).begin(), (arr).end()
#define SORTA(arr, n) sort(arr, arr + n)
#define SORT(arr) sort(arr.begin(), arr.end())
#define RSORT(arr) sort(arr.rbegin(), arr.rend())
#define SUM(arr) accumulate(arr.begin(), arr.end(), 0LL)
#define MAX(arr) *max_element(begin(arr), end(arr))
#define MIN(arr) *min_element(begin(arr), end(arr))
#define MAP map<ll, ll>
#define UMAP unordered_map<ll, ll>
#define ST set<ll>
#define UST unordered_set<ll>
#define pn cout << "NO" << "\n"
#define py cout << "YES" << '\n'
#define imp cout << -1
#define nl cout << '\n'

ll dp[1000001][2];

void STROY()
{
    int n = 1000000;
    memset(dp, 0, sizeof dp);

    dp[0][0] = dp[0][1] = 1; // {0,0} ---> 1 Vertical Cell, {0,1} --> 2 Vertical Cells

    for (int i = 1; i < n; i++)
    {
        // 1 Vertical Cell
        dp[i][0] = (2LL * dp[i - 1][0] + dp[i - 1][1]) % MOD;

        // 2 Vertical Cells
        dp[i][1] = (4LL * dp[i - 1][1] + dp[i - 1][0]) % MOD;
    }
}

int main()
{
    int t;
    cin >> t;
    STROY();

    while (t--)
    {
        int n;
        cin >> n;
        ll numOfWays = (dp[n - 1][0] + dp[n - 1][1]) % MOD;
        cout << numOfWays;
        nl;
    }
}