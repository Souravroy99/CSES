#include<bits/stdc++.h>
using namespace std ;
#define ll long long

/*
ll dp[5001][5001] ;
ll memoI(vector<int>&arr, int front, int back, bool firstTurn)
{
    if(front > back) return 0 ;
    if(dp[front][back] != -1) return dp[front][back] ;

    ll money = 0 ;
    
    if(firstTurn)
    {
        money = max(arr[front] + memoI(arr, front+1, back, !firstTurn), 
                    arr[back] + memoI(arr, front, back-1, !firstTurn)) ;
    }
    else
    {
        money = min(0 + memoI(arr, front+1, back, !firstTurn), 
                    0 + memoI(arr, front, back-1, !firstTurn)) ;
    }

    return dp[front][back] = money ;
}
memset(dp, -1, sizeof dp) ;
cout << memoI(arr, 0, n-1, true) ;
*/

int main()
{
    int n;
    cin >> n ;
    vector<int>arr(n) ;
    for(auto &it: arr) cin >> it ;

    for(int front=0 ; front<n ; front++)
    {
        for(int back=front ; back<n ; back++)
        {
            
        }
    }


}