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
ll dP[1001][1001] ;
ll memoI(vector<vector<char>> &grid, int n, int i, int j)
{
    if (i < 0 || i == n || j < 0 || j == n || grid[i][j] == '*') return 0;
    if (i == n - 1 && j == n - 1) return 1;
    if(dP[i][j] != -1) return dP[i][j] ;

    ll ans = memoI(grid, n, i, j+1)%MOD + memoI(grid, n, i+1, j)%MOD ;
    return dP[i][j] = ans%MOD ;
}
memset(dP, -1, sizeof dP) ;
cout << memoI(grid, n, 0, 0);
*/


// ll dp[1001][1001] ;
void STROY()
{
    ll n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n, '.'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j] ;
        }
    }

    // Tabulation
/*
    memset(dp, 0, sizeof dp) ;

    dp[0][0] = (grid[0][0] == '.') ;

    for(int j=1 ; j<n ; j++) {
        if(grid[0][j] == '*') break ;

        dp[0][j] = dp[0][j-1] ;
    }

    for(int i=1 ; i<n ; i++) {
        if(grid[i][0] == '*') break ;
        
        dp[i][0] = dp[i-1][0] ;
    }

    for(int i=1 ; i<n ; i++)
    {
        for(int j=1 ; j<n ; j++)
        {
            if(grid[i][j] != '*')
            {
                dp[i][j] = (dp[i-1][j]%MOD + dp[i][j-1]%MOD)%MOD ;
            }
        }
    }

    cout << dp[n-1][n-1] ;
*/


    // Space Optimization

    vll dpp(n, 0) ;

    bool flag = true ;
    dpp[0] = flag = grid[0][0] == '.' ;

    for(int j=1 ; j<n ; j++) {
        if(grid[0][j] == '*') break ;
        dpp[j] = dpp[j-1] ;
    }

    for(int i=1 ; i<n ; i++)
    {
        if(grid[i][0] == '*') flag = false ;
        vll curr(n, 0) ;

        if(flag) curr[0] = 1 ;
        else curr[0] = 0 ;

        for(int j=1 ; j<n ; j++)
        {
            if(grid[i][j] == '.')
            {
                curr[j] = (dpp[j]%MOD + curr[j-1]%MOD)%MOD ;
            }
        }
        dpp = curr ;
    }

    cout << dpp[n-1] ; 
}

int main()
{
    STROY();
}