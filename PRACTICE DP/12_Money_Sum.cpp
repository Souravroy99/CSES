#include<bits/stdc++.h>
using namespace std ;

const int N = 100000 ;
bool dp[N+1] ;

int main()
{
    int n ;
    cin >> n ;
    vector<int>arr(n);
    for(auto &it: arr) cin >> it ;
    memset(dp, 0, sizeof dp) ;
    
    dp[0] = true ;

    for(int i=0 ; i<n ; i++) {
        for(int amount=N ; amount>=arr[i] ; amount--)
        {
            dp[amount] |= dp[amount-arr[i]] ;
        }
    }

    int cnt = 0 ;
    for(int i=1 ; i<=N ; i++) {
        if(dp[i]) {
            cnt++ ;
        }
    }
    
    cout << cnt << endl ;

    for(int i=1 ; i<=N ; i++) {
        if(dp[i]) {
            cout << i << " " ;
        }
    }
}