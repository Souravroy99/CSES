// For the last two years, I have not been able to cross 'Pupil'
// This is absolutely my fault For Sure
// Today: 9th, JULY 2024
// Let's go to the next level

// Target : 'EXPERT' Before 30th, " DECEMBER 2024 "

// 1. STROY
// 2. whatever
// ...

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PINF INT_MAX
#define NINF INT_MIN
#define MOD 1000000007
#define DMOD 998244353
#define vll vector<ll>
#define vvll vector<vll>
#define pb push_back
#define pr pair<ll, ll>
#define vp vector<pair<ll, ll>>
#define vs vector<string>
#define fr(i, a, n) for (ll i = a; i < n; i++)
#define rfr(i, n, a) for (ll i = n; i >= a; i--)
#define TAKE(arr, n)            \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define ALL(arr) (arr).begin(), (arr).end()
#define SORT(arr) sort(arr.begin(), arr.end())

void STROY()
{
    ll n, k;
    cin >> n >> k;
    vll arr(n);
    TAKE(arr, n);

    auto findSubset = [&](int l, int r) -> vll
    {
        int len = r-l+1 ;
        vll res ;

        for (int i = 0; i < (1LL  << len); i++) {
            ll sum = 0 ;
            for (int bit = 0; bit < len; bit++) {
                if (i & (1 << bit)) {
                    sum += arr[bit + l] ;
                }
            }

            res.pb(sum) ;
        }

        return res ;
    };

    vll X = findSubset(0, n/2-1);
    vll Y = findSubset(n/2, n-1);

    SORT(X) ;
    SORT(Y) ;

    auto findOcc = [&](vll &arr1, vll &arr2) -> ll
    {
        ll occurrence = 0 ;
        for(ll ele: arr1)
        {
            ll lb = lower_bound(ALL(arr2), k-ele) - arr2.begin() ;
            ll ub = upper_bound(ALL(arr2), k-ele) - arr2.begin() ;

            occurrence += ub - lb ;
        }

        return occurrence ;
    };

    ll ans =  findOcc(X, Y) ;

    cout << ans ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        STROY();
        cout << endl;
    }
}