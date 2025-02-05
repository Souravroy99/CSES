#include <bits/stdc++.h>
using namespace std;
#define ll long long


/*
ll dp[5001][5001] ;

ll memoI(string &s1, string &s2, int i, int j, int n, int m)
{
    if (i == n && j == m)
        return 0;
    if (i == n || j == m)
        return max(n-i, m-j) ;

    if(dp[i][j] != -1) return dp[i][j] ;

    ll op = 1e9;
    if (s1[i] == s2[j])
    {
        op = memoI(s1, s2, i + 1, j + 1, n, m);
    }
    // Add / Remove
    op = min(op, 1 + min(memoI(s1, s2, i, j + 1, n, m), memoI(s1, s2, i + 1, j, n, m)));

    // Replace
    op = min(op, 1 + memoI(s1, s2, i + 1, j + 1, n, m)) ;

    return dp[i][j] = op;
}
memset(dp, -1, sizeof dp) ;
cout << memoI(s1, s2, 0, 0, n, m);
*/

ll dpp[5001][5001] ;
void STROY()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();

    memset(dpp, 0, sizeof dpp) ;

    for(int i=0 ; i<n ; i++) {
        dpp[i][m] = n-i ;
    }

    for(int j=0 ; j<m ; j++) {
        dpp[n][j] = m-j ;
    }
        

    for(int i=n-1 ; ~i ; i--)
    {
        for(int j=m-1 ; ~j ; j--)
        {
            ll op = 1e9;
            if (s1[i] == s2[j])
            {
                op = dpp[i + 1][j + 1] ;
            }
            // Add / Remove
            op = min(op, 1 + min(dpp[i][j + 1], dpp[i + 1][j]));

            // Replace
            op = min(op, 1 + dpp[i + 1][j + 1]) ;

            dpp[i][j] = op;
        }
    }

    cout << dpp[0][0] ;
}

int main()
{
    int t = 1;
    // cin >> t;

    while (t--)
    {
        STROY();
        cout << endl ;
    }
}