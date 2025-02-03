#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define mod 1000000007

int main()
{ 
    int n, sum ;
    cin >> n >> sum ;
    vector<int>arr(n,0) ;
    for(int i=0; i<n ; i++) cin>>arr[i] ;

    vector<ll>dp(sum+1, 0) ;
    dp[0] = 1 ;

    for(int s=0 ; s<=sum ; s++) if(s%arr[0] == 0) dp[s] = 1 ;

    for(int i=1 ; i<n ; i++)
    {
        for(int s=arr[i] ; s<=sum ; s++)
        {
            dp[s] += dp[s-arr[i]] ;
            dp[s] %= mod ;
        }
    }

    cout << dp[sum] ;
}