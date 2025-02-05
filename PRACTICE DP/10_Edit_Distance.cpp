#include <bits/stdc++.h>
using namespace std ;

// Space Optimization
int main()
{
    string s1, s2 ;
    cin >> s1 >> s2 ;

    int n = s1.length(), m = s2.length() ;

    vector<int>dp(m+1), curr(m+1) ;
    
    for(int i=n ; i>=0 ; i--)
    {
        for(int j=m ; j>=0 ; j--)
        {
            if(i==n || j==m) {
                curr[j] = (n-i) + (m-j) ; // max(n-i, m-j)
            }
            else {
                int op = (s1[i] != s2[j]) + dp[j+1] ;
                int add = 1 + curr[j+1] ;
                int remove = 1 + dp[j] ;

                curr[j] = min({op, add, remove}) ;
            }
        }
        dp = curr ;
    }

    cout << dp[0] ;
}










/* ACCEPTED
// Changing string s1, s2 is reference string(i.e, converting s1 to s2)
int dp[5001][5001] ;

int memoI(string &s1, string &s2, int n, int m, int i, int j)
{
    if(i==n && j==m) return 0 ;
    if(i==n || j==m) return max(n-i, m-j) ;

    if(dp[i][j] != -1) return dp[i][j] ;

    int operations = (s1[i] != s2[j]) + memoI(s1, s2, n, m, i+1, j+1) ;

    int add = 1 + memoI(s1, s2, n, m, i, j+1) ;
    int remove = 1 + memoI(s1, s2, n, m, i+1, j) ;

    operations = min({operations, add, remove}) ;

    return dp[i][j] = operations ;
}
memset(dp, -1, sizeof dp) ;
cout << memoI(s1, s2, n, m, 0, 0) ;
*/



/* ACCEPTED
int main()
{
    string s1, s2 ;
    cin >> s1 >> s2 ;

    int n = s1.length(), m = s2.length() ;

    vector<vector<int>>dp(n+1, vector<int>(m+1, n+m)) ;
 
    for(int i=n ; i>=0 ; i--)
    {
        for(int j=m ; j>=0 ; j--)
        {
            if(i==n || j==m) {
                dp[i][j] = max(n-i, m-j) ;
            }
            else {
                int operations = (s1[i] != s2[j]) + dp[i+1][j+1] ;
                int add = 1 + dp[i][j+1] ;
                int remove = 1 + dp[i+1][j] ;

                dp[i][j] = min({operations, add, remove}) ;
            }
        }
    }

    cout << dp[0][0] ;
}
*/