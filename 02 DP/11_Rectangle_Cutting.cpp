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

/*
ll dp[501][501];

int memoI(int a, int b)
{
    if (a == b)
        return 0; // Square
    if (dp[a][b] != -1)
        return dp[a][b];

    int cut = PINF;

    for (int i = 1; i < a; i++)
        cut = min(cut, 1 + memoI(i, b) + memoI(a - i, b));

    for (int j = 1; j < b; j++)
        cut = min(cut, 1 + memoI(a, j) + memoI(a, b - j));

    return dp[a][b] = cut;
}
memset(dp, -1, sizeof dp);
cout << memoI(a, b);
*/

void STROY()
{
    int a, b;
    cin >> a >> b;

    int dpp[a + 1][b + 1];
    memset(dpp, 0, sizeof dpp);

    for (int len = 1; len <= a; len++)
    {
        for (int wid = 1; wid <= b; wid++)
        {
            int cut = PINF;
            if(len == wid) cut = 0 ;

            for (int l = 1; l < len; l++)
            {
                cut = min(cut, 1 + dpp[l][wid] + dpp[len - l][wid]);
            }

            for (int w = 1; w < wid; w++)
            {
                cut = min(cut, 1 + dpp[len][w] + dpp[len][wid - w]);
            }

            dpp[len][wid] = cut ;
        }
    }

    cout << dpp[a][b];
}

int main()
{
    int t = 1;
    // cin >> t;

    while (t--)
    {
        STROY();
        nl;
    }
}
