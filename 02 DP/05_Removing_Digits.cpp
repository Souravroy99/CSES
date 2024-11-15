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
#define LPINF LONG_LONG_MAX
#define LNINF LONG_LONG_MIN
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
#define SORTA(arr, n) sort(arr, arr + n)
#define SORT(arr) sort(arr.begin(), arr.end())
#define RSORT(arr) sort(arr.rbegin(), arr.rend())
#define SUM(arr) accumulate(arr.begin(), arr.end(), 0LL)
#define MAX(arr) *max_element(begin(arr), end(arr))
#define MIN(arr) *min_element(begin(arr), end(arr))
#define MAP map<ll, ll>
#define UMAP unordered_map<ll, ll>
#define ST set<ll>
#define UST unordered_set<ll>
#define pn cout << "NO" << "\n"
#define py cout << "YES" << '\n'
#define imp cout << -1
#define nl cout << '\n'

/*
ll dp[1000001];
int memoI(int n)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int ans = 1e9, amount = n;

    while (amount > 0)
    {
        int lastDigit = amount % 10;

        if (lastDigit != 0)
            ans = min(ans, 1 + memoI(n - lastDigit));

        amount /= 10;
    }

    return dp[n] = ans;
}
memset(dp, -1, sizeof dp);
cout << memoI(n);
*/

ll dP[1000001];

void STROY()
{
    ll n;
    cin >> n;

    memset(dP, 0, sizeof dP);

    for (int num = 1; num <= n; num++)
    {
        ll amount = num, ans = n;

        while (amount > 0)
        {
            int digit = amount % 10;
            
            if (digit != 0)
            {
                ans = min(ans, 1 + dP[num - digit]);
            }

            amount /= 10 ;
        }

        dP[num] = ans ;
    }

    cout << dP[n];
}

int main()
{
    STROY();
}