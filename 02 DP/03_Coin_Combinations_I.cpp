// For the last two years, I have not been able to cross 'Pupil'
// This is absolutely my fault For Sure
// Today: 9th, JULY 2024
// Let's go to the next level
 
// Target : 'EXPERT' Before 30th, " DECEMBER 2024 "
 
// 1. STROY
// 2. whatever
// ...
 
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
ll dp[1000001];
int memoI(vll &coins, ll amount)
{
    if (amount <= 0)
        return (amount == 0);
    if (dp[amount] != -1)
        return dp[amount];
    ll ans = 0;
 
    for (int i = 0; i < (int)coins.size(); i++) {
        ans = (ans % MOD + memoI(coins, amount - coins[i]) % MOD) % MOD;
    }
 
    return dp[amount] = ans;
}
memset(dp, -1, sizeof dp) ;
cout << memoI(coins, amount) ;
*/
 
 
ll DP[1000001] ;

void STROY()
{
    ll n, amount;
    cin >> n >> amount;
    vll coins(n);
    TAKE(coins, n);
 
    memset(DP, 0, sizeof DP);
    DP[0] = 1 ;
 
    for(int tar=1 ; tar<=amount ; tar++)
    {
        for(int i=0 ; i<n ; i++)
        {
            if(coins[i] <= tar)
            {
                DP[tar] += DP[tar-coins[i]] ;
                DP[tar] %= MOD ;
            }
        }
    }
 
    cout << DP[amount] ;
}
 
int main()
{
    STROY();
}