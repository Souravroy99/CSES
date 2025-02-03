#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007

int main()
{
    int n, target;
    cin >> n >> target ;
    vector<int>arr(n) ;
    for(int i=0 ; i<n ; i++) cin >> arr[i] ;

    vector<long long>dp(target+1, 0) ;
    dp[0] = 1 ;

    for(int sum=1 ; sum<=target ; sum++)
    {
        for(int i=0 ; i<n ; i++)
        {
            if(sum >= arr[i]) {
                dp[sum] += dp[sum-arr[i]] ;
                dp[sum] %= mod ;
            }
        }
    }

    cout << dp[target] ;
}


/*  MLE
int memoI(vector<int>&arr, int n, int s)
{
    if(s < 0) return 0 ;
    if(s == 0) return 1 ;
    int ways = 0 ;

    for(int i=0 ; i<n ; i++) {
        ways = ways%mod + memoI(arr, n, s-arr[i])%mod ;
    }

    return ways ;
}
cout << memoI(arr, n, s) ;
*/