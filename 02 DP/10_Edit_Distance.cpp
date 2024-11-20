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
ll dp[5001][5001] ;

ll memoI(string &s1, string &s2, int i, int j, int n, int m)
{
    if (i == n && j == m)
        return 0;
    if (i == n || j == m)
        return max(n-i, m-j) ;

    if(dp[i][j] != -1) return dp[i][j] ;

    ll op = 1e9;
    if (s1[i] == s2[j])
    {
        op = memoI(s1, s2, i + 1, j + 1, n, m);
    }
    // Add / Remove
    op = min(op, 1 + min(memoI(s1, s2, i, j + 1, n, m), memoI(s1, s2, i + 1, j, n, m)));

    // Replace
    op = min(op, 1 + memoI(s1, s2, i + 1, j + 1, n, m)) ;

    return dp[i][j] = op;
}
memset(dp, -1, sizeof dp) ;
cout << memoI(s1, s2, 0, 0, n, m);
*/

ll dpp[5001][5001] ;
void STROY()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();

    memset(dpp, 0, sizeof dpp) ;

    for(int i=0 ; i<n ; i++) {
        dpp[i][m] = n-i ;
    }

    for(int j=0 ; j<m ; j++) {
        dpp[n][j] = m-j ;
    }
        

    for(int i=n-1 ; ~i ; i--)
    {
        for(int j=m-1 ; ~j ; j--)
        {
            ll op = 1e9;
            if (s1[i] == s2[j])
            {
                op = dpp[i + 1][j + 1] ;
            }
            // Add / Remove
            op = min(op, 1 + min(dpp[i][j + 1], dpp[i + 1][j]));

            // Replace
            op = min(op, 1 + dpp[i + 1][j + 1]) ;

            dpp[i][j] = op;
        }
    }

    cout << dpp[0][0] ;
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