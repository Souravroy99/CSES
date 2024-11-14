#include<bits/stdc++.h>
using namespace std ;
#define ll long long

int main()
{
    int n ;
    cin >> n ;
    vector<ll>arr(n) ;
    for(auto &i: arr) cin >> i ;

    ll mxSum=-1e15, sum=0 ;
    for(int i=0 ; i<n ; i++)
    {
        sum += arr[i] ;
        mxSum = max(mxSum, sum) ;
        if(sum<0) sum=0;
    }

    cout << mxSum ;
}