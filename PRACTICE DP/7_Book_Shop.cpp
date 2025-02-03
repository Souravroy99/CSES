#include<bits/stdc++.h>
using namespace std ;

int dp[1001][1001] ;
int memoI_maximum_number_of_pages(vector<int>&price, vector<int>&page, int maxPrice, int n, int idx)
{
    if(idx == n) return 0 ;
    if(dp[maxPrice][idx] != -1) return dp[maxPrice][idx] ;

    int not_pick = memoI_maximum_number_of_pages(price, page, maxPrice, n, idx+1) ;
    int pick = 0 ;

    if(price[idx] <= maxPrice) {
        pick = page[idx] + memoI_maximum_number_of_pages(price, page, maxPrice - price[idx], n, idx+1) ;
    }

    return dp[maxPrice][idx] = max(not_pick, pick) ;
}

int main()
{
    int n, x ;
    cin >> n >> x ;
    vector<int>price(n), page(n) ;

    for(auto &pr: price) cin >> pr ;
    for(auto &pg: page) cin >> pg ;

    memset(dp, -1, sizeof dp) ;
    cout << memoI_maximum_number_of_pages(price, page, x, n, 0) ;
}