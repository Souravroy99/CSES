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
int memoI(vll &h, vll &s, int n, int x, int idx)
{
    if(idx==n) return 0 ;
    if(dP[idx][x] != -1) return dP[idx][x] ;

    int np = memoI(h, s, n, x, idx+1) ;
    int p=0 ;

    if(h[idx] <= x) p = s[idx] + memoI(h, s, n, x-h[idx], idx+1) ;

    return dP[idx][x] = max(p, np) ;
}
memset(dP, -1, sizeof dP) ;
cout << memoI(h, s, n, x, 0) ;
*/


ll dp[100001] ;
ll curr[100001] ;

void STROY()
{
    int n, x ;
    cin >> n >> x ;
    vll h(n,0), s(n,0) ;

    fr(i,0,n) cin >> h[i] ;
    fr(i,0,n) cin >> s[i] ;

    memset(dp, 0, sizeof dp) ;
    for(int i=h[0] ; i<=x ; i++) dp[i] = s[0] ;

    for(int idx=1 ; idx<n ; idx++)
    {
        for(int amount=0 ; amount<=x ; amount++)
        {
            curr[amount] = max(dp[amount], (h[idx] <= amount ? s[idx] + dp[amount - h[idx]] : 0)) ;    
        }

        for(int i=0 ; i<=100000 ; i++) dp[i] = curr[i] ;
    }

    cout << dp[x] ;
}

int main() {
    STROY();
}