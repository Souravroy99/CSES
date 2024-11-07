#include<bits/stdc++.h>
using namespace std ;
#define ll long long

int main()
{
    int n ;
    cin >> n ;
    vector<ll>arr(n) ;

    for(auto &i: arr) {
        cin >> i ;
    }

    ll ans = 1e15, sum=0, sum1=0;
    sort(arr.begin(), arr.end()) ;

    for(int i=0 ; i<n ; i++) {
        sum += abs(arr[n/2] - arr[i]) ;
        sum1 += abs(arr[max(0, n/2 - 1)] - arr[i]) ;
    }

    cout << min(sum, sum1) ;
}