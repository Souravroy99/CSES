#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define vvll vector<vll>


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
            dp[j] %= MOD ;
        }
    }

    int number_of_paths = (mat[n-1][n-1] != '*') ? dp[n-1] : 0 ;
    cout << number_of_paths ;
}





/*
ll dP[1001][1001] ;
ll memoI(vector<vector<char>> &grid, int n, int i, int j)
{
    if (i < 0 || i == n || j < 0 || j == n || grid[i][j] == '*') return 0;
    if (i == n - 1 && j == n - 1) return 1;
    if(dP[i][j] != -1) return dP[i][j] ;

    ll ans = memoI(grid, n, i, j+1)%MOD + memoI(grid, n, i+1, j)%MOD ;
    return dP[i][j] = ans%MOD ;
}
memset(dP, -1, sizeof dP) ;
cout << memoI(grid, n, 0, 0);
*/


// ll dp[1001][1001] ;
void STROY()
{
    ll n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n, '.'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j] ;
        }
    }

    // Tabulation
/*
    memset(dp, 0, sizeof dp) ;

    dp[0][0] = (grid[0][0] == '.') ;

    for(int j=1 ; j<n ; j++) {
        if(grid[0][j] == '*') break ;

        dp[0][j] = dp[0][j-1] ;
    }

    for(int i=1 ; i<n ; i++) {
        if(grid[i][0] == '*') break ;
        
        dp[i][0] = dp[i-1][0] ;
    }

    for(int i=1 ; i<n ; i++)
    {
        for(int j=1 ; j<n ; j++)
        {
            if(grid[i][j] != '*')
            {
                dp[i][j] = (dp[i-1][j]%MOD + dp[i][j-1]%MOD)%MOD ;
            }
        }
    }

    cout << dp[n-1][n-1] ;
*/


    // Space Optimization

    vector<ll> dpp(n, 0) ;

    bool flag = true ;
    dpp[0] = flag = grid[0][0] == '.' ;

    for(int j=1 ; j<n ; j++) {
        if(grid[0][j] == '*') break ;
        dpp[j] = dpp[j-1] ;
    }

    for(int i=1 ; i<n ; i++)
    {
        if(grid[i][0] == '*') flag = false ;
        vector<ll> curr(n, 0) ;

        if(flag) curr[0] = 1 ;
        else curr[0] = 0 ;

        for(int j=1 ; j<n ; j++)
        {
            if(grid[i][j] == '.')
            {
                curr[j] = (dpp[j]%MOD + curr[j-1]%MOD)%MOD ;
            }
        }
        dpp = curr ;
    }

    cout << dpp[n-1] ; 
}

int main()
{
    STROY();
}