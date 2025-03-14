#include<bits/stdc++.h>
using namespace std ;

int dp[100001] ;

int main()
{
    int n, x ;
    cin >> n >> x ;
    vector<int>price(n), page(n) ;

    for(auto &pr: price) cin >> pr ;
    for(auto &pg: page) cin >> pg ;

    memset(dp, 0, sizeof dp) ;

    for(int i=0 ; i<n ; i++)
    {
        for(int amount=x ; amount>=price[i] ; amount--)
        {
            dp[amount] = max(dp[amount], page[i] + dp[amount - price[i]]) ;
        }
    }

    cout << dp[x] ;
}