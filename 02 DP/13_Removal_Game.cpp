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
ll memoI(vll &arr, int i, int j)
{
    if (i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j] ;

    ll score1 = arr[i] + min(memoI(arr, i+1, j-1), memoI(arr, i+2, j)) ;
    ll score2 = arr[j] + min(memoI(arr, i+1, j-1), memoI(arr, i, j-2)) ;

    return dp[i][j] = max(score1, score2) ;
}
memset(dp, -1, sizeof dp) ;
cout << memoI(arr, 0, n-1);
*/



/*
ll dp[5001][5001];
memset(dp, 0, sizeof dp);

for (int i = n - 1; i >= 0; i--)
{
    for (int j = i; j < n; j++)
    {
        ll score1 = arr[i] + min(dp[i + 1][j - 1], dp[i + 2][j]);
        ll score2 = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);

        dp[i][j] = max(score1, score2);
    }
}
cout << dp[0][n-1];
*/


void STROY()
{
    int n;
    cin >> n;
    vll arr(n);
    TAKE(arr, n);

    vector<ll>dp1(n+1,0), dp2(n+1,0), curr(n+1,0) ;

    for(int i=n-1 ; ~i ; i--)
    {
        for(int j=i ; j<n ; j++)
        {
            ll score1 = arr[i] + min(dp1[j-1], dp2[j]) ;
            ll score2 = arr[j] + min(dp1[j-1], curr[j-2]) ;

            curr[j] = max(score1, score2) ;
        }

        dp2 = dp1 ;
        dp1 = curr ;
    }

    cout << curr[n-1] ;
}

int main()
{
    int t = 1;
    while (t--)
    {
        STROY();
        nl;
    }
}
