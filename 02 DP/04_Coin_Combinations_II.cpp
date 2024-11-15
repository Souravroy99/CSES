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
#define pmo cout << -1
#define imp cout << -1
#define nl cout << '\n'


void STROY()
{
    int n, amount;
    cin >> n >> amount ;
    vll coins(n) ;
    TAKE(coins, n) ;

    vll dp(amount+1, 0), curr(amount+1, 0) ;

    for(int i=0 ; i<=amount ; i++) {
        if(i%coins[0] == 0) dp[i] = curr[i] = 1 ;
    }

    for(int i=1 ; i<n ; i++)
    {
        for(int target=1 ; target<=amount ; target++)
        {
            int np = dp[target] ;
            int p = 0 ;

            if(coins[i] <= target) p = curr[target-coins[i]] ;

            curr[target] = (np%MOD + p%MOD)%MOD ;
        }

        dp = curr ;
    }

    cout << dp[amount] ;
}


int main()
{
    STROY();
}