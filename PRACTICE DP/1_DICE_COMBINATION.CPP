#include<bits/stdc++.h>
using namespace std ;
#define MOD 1000000007

int dp[1000001] ;

int memoI(int n)
{
    if(n < 0) return 0 ;
    if(n == 0) return 1 ;
    if(dp[n] != -1) return dp[n] ;

    int ways=0 ;
    for(int dice=1 ; dice<=6 ; dice++) 
    {
        ways = ways%MOD + memoI(n-dice)%MOD ;
    }

    return dp[n] = ways%MOD ;
}

int tabulation(int n)
{ 
    dp[0] = 1 ;
    for(int num=1 ; num<=n ; num++)
    {
        for(int dice=1 ; dice<=min(num,6) ; dice++)
        {
            dp[num] = (dp[num]%MOD + dp[num-dice]%MOD)%MOD ;
        }
    }

    return dp[n] ;
}

int main()
{
    int n ;
    cin >> n ;
    // memset(dp, -1, sizeof dp) ;
    // cout << memoI(n) ;

    memset(dp, 0, sizeof dp) ;
    cout << tabulation(n) ;
}