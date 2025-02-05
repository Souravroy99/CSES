#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define vll vector<ll>
#define vvll vector<vll>
#define fr(i, a, n) for (ll i = a; i < n; i++)

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