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
ll dp[101][100001] ;
int size = 0 ;

bool memoI(vll &arr, int i, int n, int sum)
{
    if(i==n) {
        if(sum != 0 && dp[i][sum] == -1) {
            size++ ;
        }

        return dp[i][sum] = true ;
    }

    if(dp[i][sum] != -1) return dp[i][sum] ;

    int exclude = memoI(arr, i+1, n, sum) ;
    int include = memoI(arr, i+1, n, sum+arr[i]) ;

    return dp[i][sum] = (exclude || include) ;
}
memset(dp, -1, sizeof dp) ;
memoI(arr, 0, n, 0) ;

cout << size << endl ;
for(int sum=1 ; sum<=totalSum ; sum++)
{
    if(dp[n][sum] == true)
        cout << sum << " " ;
}
*/



/*
    bool dp[101][100001] ;
    for(int i=0 ; i<n ; i++) {
        dp[i][0] = true ;
    }
    dp[0][arr[0]] = true ;

    for(int i=1 ; i<n ; i++)
    {
        for(int sum=1 ; sum<=totalSum ; sum++)
        {
            dp[i][sum] = dp[i-1][sum] || ((arr[i] <= sum) ? dp[i-1][sum-arr[i]] : false) ;
        }
    }

    int size = 0 ;
    for(int sum=1 ; sum<=totalSum ; sum++) {
        size += dp[n-1][sum] ;
    }

    cout << size << endl ;
    for(int sum=1 ; sum<=totalSum ; sum++) {
        if(dp[n-1][sum] == true)
            cout << sum << " " ;
    }
*/


bool dpp[100001];

void STROY()
{
    int n;
    cin >> n;
    vll arr(n);
    TAKE(arr, n);
    int totalSum = SUM(arr);

    dpp[0] = dpp[arr[0]] = true;
    int size = 1;

    for (int i = 1; i < n; i++)
    {
        size = 0;

        for (int sum = totalSum; sum >= 1; sum--)
        {
            dpp[sum] = dpp[sum] || ((arr[i] <= sum) ? dpp[sum - arr[i]] : false);
            size += dpp[sum];
        }
    }

    cout << size << endl;
    for (int sum = 1; sum <= totalSum; sum++)
    {
        if (dpp[sum] == true)
            cout << sum << " ";
    }
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
