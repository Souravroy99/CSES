#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define TAKE(arr, n)            \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]


void STROY()
{
    ll n ;
    cin >> n ;
    vll arr(n);
    TAKE(arr, n);

    ll sum=0, cnt=0 ;
    unordered_map<ll,ll> mp ;
    mp[0] = 1 ;

    for(int i=0 ; i<n ; i++)
    {
        sum += arr[i] ;
        cnt += mp[(sum%n+n)%n] ;
        mp[(sum%n+n)%n]++ ;
    }

    cout << cnt ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--)
    {
        STROY();
        cout << endl;
    }
}