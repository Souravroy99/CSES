#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

/*
// ACCEPTED
ll dp[102][100001] ;

int memoI(vector<int>&arr, int range, int n, int i, int prevVal)
{
    if(i == n) return 1 ;

    if(dp[prevVal][i] != -1) return dp[prevVal][i] ;

    ll no_change = 0 ;
    ll do_change = 0 ;

    if(arr[i] != 0)
    {
        if(i == 0 || abs(arr[i] - prevVal) <= 1)
            no_change = memoI(arr, range, n, i+1, arr[i]) ;
    }
    else
    {
        if(i == 0)
        {
            for(int val=1 ; val<=range ; val++)
            {
                do_change += memoI(arr, range, n, i+1, val) ;
            }
        }
        else
        {
            for(int dVal=-1 ; dVal<=+1 ; dVal++)
            {
                int newVal = prevVal+dVal ;

                if(newVal >= 1 && newVal <= range)
                    do_change += memoI(arr, range, n, i+1, newVal) ;
            }
        }
    }

    return dp[prevVal][i] = (no_change + do_change)%mod ;
}

memset(dp, -1, sizeof dp) ;
cout << memoI(arr, range, n, 0, 0) ;
*/




int main()
{
    int n, range;
    cin >> n >> range;
    vector<int> arr(n);
    for (auto &val : arr)
        cin >> val;

    vector<ll> dp(range + 1, 0);

// Base Case
    for (int val = 1; val <= range; val++)
    {
        if(arr[0] == 0 || arr[0] == val)
            dp[val] = 1;
    }


    for (int i = 1; i < n; i++)
    {
        vector<ll> curr(range + 1, 0);

        for (int val = 1; val <= range; val++)
        {
            if (arr[i] != 0 && val != arr[i]) continue ;

            for (int dx = -1; dx <= +1; dx++)
            {
                int newVal = val + dx;
                if (newVal >= 1 && newVal <= range)
                {
                    curr[val] += dp[newVal];
                    curr[val] %= mod;
                }
            }
        }
        swap(dp, curr) ;
    }

    ll numberOfArr = accumulate(dp.begin(), dp.end(), 0LL) % mod ; 

    if (arr[n - 1] != 0)
        numberOfArr = dp[arr[n - 1]] ;

    cout << numberOfArr ;
}