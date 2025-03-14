#include <bits/stdc++.h>
using namespace std ;

/*
int dp[501][501] ;

int memoI(int length, int width)
{
    if(length == width) return 0 ; // Square

    if(dp[length][width] != -1) return dp[length][width] ;

    int cut = length*width ;

    auto efficient_cut = [&](int length, int width) -> void
    {
        for(int row=1 ; row<length ; row++) {
            cut = min(cut, 1 + memoI(row, width) + memoI(length-row, width)) ;
        }
    };

    efficient_cut(length, width) ;
    efficient_cut(width, length) ;

    return dp[length][width] = cut ;
}
memset(dp, -1, sizeof dp) ;
cout << memoI(n, m) ;
*/


int main()
{
    int n, m ;
    cin >> n >> m ;

    vector<vector<int>>dp(n+1, vector<int>(m+1, 0)) ;

    for(int len=1 ; len<=n ; len++)
    {
        for(int wid=1 ; wid<=m ; wid++)
        {
            int cut = n*m ;
            if(len == wid) cut = 0 ;

            for(int l=1 ; l<len ; l++) {
                cut = min(cut, 1+dp[l][wid]+dp[len-l][wid]) ;
            }
            
            for(int w=1 ; w<wid ; w++) {
                cut = min(cut, 1+dp[len][w]+dp[len][wid-w]) ;
            }

            dp[len][wid] = cut ;
        }
    }
 
    cout << dp[n][m] ;
}