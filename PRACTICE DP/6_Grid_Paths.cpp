#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007

//  MOST SPACE OPTIMIZE

int main()
{
    int n;
    cin>>n ;
    vector<vector<char>>mat(n, vector<char>(n)) ;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cin >> mat[i][j] ;
        }
    }
    vector<int>dp(n, 0) ;

    for(int j=0 ; j<n ; j++) 
    {
        if(mat[0][j] == '*') break ;
        else dp[j] = 1 ;
    }

    bool flag = dp[0] ;

    for(int i=1 ; i<n ; i++)
    {
        if(mat[i][0] == '*') flag = false ;
        dp[0] = flag ;

        for(int j=1 ; j<n ; j++)
        {
            if(mat[i][j] == '*') continue ;

            int isRightPathPossible = mat[i][j-1] != '*' ;
            int isDownPathPossible  = mat[i-1][j] != '*' ;

            dp[j] = (isDownPathPossible ? dp[j] : 0) + (isRightPathPossible ? dp[j-1] : 0) ;
            dp[j] %= mod ;
        }
    }

    int number_of_paths = (mat[n-1][n-1] != '*') ? dp[n-1] : 0 ;
    cout << number_of_paths ;
}









/* ACCEPTED
int main()
{
    int n;
    cin>>n ;
    vector<vector<char>>mat(n, vector<char>(n)) ;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cin >> mat[i][j] ;
        }
    }
    vector<vector<int>>dp(n, vector<int>(n, 0)) ;

    for(int j=0 ; j<n ; j++) 
    {
        if(mat[0][j] == '*') break ;
        else dp[0][j] = 1 ;
    }

    for(int i=0 ; i<n ; i++) 
    {
        if(mat[i][0] == '*') break ;
        else dp[i][0] = 1 ;
    }
    

    for(int i=1 ; i<n ; i++)
    {
        for(int j=1 ; j<n ; j++)
        {
            if(mat[i][j] == '*') continue; 
            dp[i][j] += dp[i-1][j] + dp[i][j-1] ;
            dp[i][j] %= mod ;
        }
    }

    cout << dp[n-1][n-1] ;
}
*/