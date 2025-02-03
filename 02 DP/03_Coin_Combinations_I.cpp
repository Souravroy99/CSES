#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define vll vector<ll>
#define TAKE(arr, n)            \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
 
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