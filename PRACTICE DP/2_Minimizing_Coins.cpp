#include<bits/stdc++.h>
using namespace std ;
#define MOD 1000000007

/*
int dpp[101][1000001] ;

int memoI(int i, int n, int sum, vector<int>&arr)
{
    if(sum < 0) return 1e9 ;
    if(i==n) return sum==0 ? 0 : 1e9 ;
    if(dpp[i][sum] != -1) return dpp[i][sum] ;

    int not_pick = memoI(i+1, n, sum, arr) ;
    int pick = 1+memoI(i, n, sum-arr[i], arr) ;

    return dpp[i][sum] = min(not_pick, pick) ; 
}
// memset(dpp, -1, sizeof dpp) ;
// cout << memoI(0, n, sum, arr) ;
*/

int main()
{
    int n, sum ;
    cin >> n >> sum ;
    vector<long long>arr(n) ;
    for(auto &it : arr) cin >> it ;

    int INF = 1e9 ;
    vector<int>dp(sum+1, INF) ;

    dp[0] = 0 ;
    for(int k=1 ; k<=sum ; k++) {
        if(k%arr[0] == 0) {
            dp[k] = k/arr[0] ;
        }
    }

    for(int i=1 ; i<n ; i++)
    {
        for(int k=arr[i] ; k<=sum ; k++)
        {
            dp[k] = min(dp[k], 1+dp[k-arr[i]]) ;
        }
    }

    // for(auto it : dp) cout << it << " " ;
    // cout<<endl ;

    int val = dp[sum] >= INF ? -1 : dp[sum] ;
    cout << val ;
}