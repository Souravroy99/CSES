#include<bits/stdc++.h>
using namespace std ;

/* ACCEPTED
const int N = 1000001 ;
int dpp[N] ;

int memoI(int n)
{
    if(n < 0) return 1e9 ;
    if(n == 0) return 0 ;
    if(dpp[n] != -1) return dpp[n] ;

    int temp = n ;
    int steps = 1e9 ;

    while(temp != 0)
    {
        int digit = temp%10 ;
        temp /= 10 ;
        if(digit == 0) continue;

        steps = min(steps, 1+memoI(n-digit)) ;
    }

    return dpp[n] = steps ;
}
memset(dpp, -1, sizeof dpp) ;
cout << memoI(n) ;
*/

int main()
{
    int n ;
    cin >> n ;

    vector<int>dp(n+1, 1e9) ;
    dp[0] = 0 ;

    for(int num=1 ; num<=n ; num++)
    {
        int temp = num ;
        while(temp>0)
        {
            int digit = temp%10 ;
            temp /= 10 ;
            if(digit == 0) continue ;

            dp[num] = min(dp[num], 1+dp[num-digit]) ; 
        }
    }

    cout << dp[n] ;
}