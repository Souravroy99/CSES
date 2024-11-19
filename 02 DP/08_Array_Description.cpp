// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define LPINF LONG_LONG_MAX
// #define LNINF LONG_LONG_MIN
// #define PINF INT_MAX
// #define NINF INT_MIN
// #define MOD 1000000007
// #define DMOD 998244353
// #define vll vector<ll>
// #define vvll vector<vll>
// #define pb push_back
// #define pr pair<ll, ll>
// #define vp vector<pair<ll, ll>>
// #define vs vector<string>
// #define fr(i, a, n) for (ll i = a; i < n; i++)
// #define rfr(i, n, a) for (ll i = n; i >= a; i--)
// #define TAKE(arr, n)            \
//     for (int i = 0; i < n; i++) \
//     cin >> arr[i]
// #define ALL(arr) (arr).begin(), (arr).end()
// #define SORTA(arr, n) sort(arr, arr + n)
// #define SORT(arr) sort(arr.begin(), arr.end())
// #define RSORT(arr) sort(arr.rbegin(), arr.rend())
// #define SUM(arr) accumulate(arr.begin(), arr.end(), 0LL)
// #define MAX(arr) *max_element(begin(arr), end(arr))
// #define MIN(arr) *min_element(begin(arr), end(arr))
// #define MAP map<ll, ll>
// #define UMAP unordered_map<ll, ll>
// #define ST set<ll>
// #define UST unordered_set<ll>
// #define pn cout << "NO" << "\n"
// #define py cout << "YES" << '\n'
// #define imp cout << -1
// #define nl cout << '\n'

// /*
// ll dp[100001][201];

// ll memoI(vll &arr, int idx, int n, int m)
// {
//     if (idx == n)
//         return 1;
//     if (idx > 0 && arr[idx] != 0 && (abs(arr[idx - 1] - arr[idx]) > 1))
//         return 0;

//     if (dp[idx][arr[max(0, idx - 1)]] != -1)
//         return dp[idx][arr[max(0, idx - 1)]];

//     ll dec = 0, neu = 0, inc = 0, justSkip = 0;

//     if (arr[idx] == 0)
//     {
//         if (idx == 0)
//         {
//             for (int num = 1; num <= m; num++)
//             {
//                 arr[idx] = num;
//                 inc = (inc % MOD + memoI(arr, idx + 1, n, m) % MOD) % MOD;
//             }
//         }
//         else
//         {
//             if (arr[idx - 1] >= 2 && arr[idx - 1] <= m)
//             {
//                 arr[idx] = arr[idx - 1] - 1;
//                 dec = memoI(arr, idx + 1, n, m);
//             }

//             if (arr[idx - 1] >= 1 && arr[idx - 1] <= m)
//             {
//                 arr[idx] = arr[idx - 1];
//                 neu = memoI(arr, idx + 1, n, m);
//             }

//             if (arr[idx - 1] >= 1 && arr[idx - 1] < m)
//             {
//                 arr[idx] = arr[idx - 1] + 1;
//                 inc = memoI(arr, idx + 1, n, m);
//             }

//         }

//         arr[idx] = 0;
//     }
//     else
//     {
//         justSkip = memoI(arr, idx + 1, n, m);
//     }

//     return dp[idx][arr[max(0, idx - 1)]] = max((dec % MOD + neu % MOD + inc % MOD) % MOD, justSkip % MOD);
// }
// memset(dp, -1, sizeof dp);
// cout << memoI(arr, 0, n, m);
// */



#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define vll vector<ll>
#define TAKE(arr, n)            \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]

ll dp[100001][201];

void STROY()
{
    int n, m;
    cin >> n >> m;
    vll arr(n);
    TAKE(arr, n);

    memset(dp, 0, sizeof dp);

    // Base case for the last index
    if (arr[n - 1] == 0) {
        for (int num = 1; num <= m; num++) {
            dp[n - 1][num] = 1;
        }
    } else {
        dp[n - 1][arr[n - 1]] = 1;
    }

    // Iterate over the array from n-2 to 0
    for (int idx = n - 2; idx >= 0; idx--) {
        // Compute prefix sums for the current row
        vector<ll> prefix(m + 2, 0); // Use m+2 for boundary safety
        for (int num = 1; num <= m; num++) {
            prefix[num] = (prefix[num - 1] + dp[idx + 1][num]) % MOD;
        }

        // Transition using prefix sums
        for (int num = 1; num <= m; num++) {
            if (arr[idx] == 0 || arr[idx] == num) {
                ll low = max(1, num - 1);
                ll high = min(m, num + 1);
                dp[idx][num] = (prefix[high] - prefix[low - 1] + MOD) % MOD;
            }
        }
    }

    // Calculate the result from the first index
    ll result = 0;
    if (arr[0] == 0) {
        for (int num = 1; num <= m; num++) {
            result = (result + dp[0][num]) % MOD;
        }
    } else {
        result = dp[0][arr[0]];
    }

    cout << result << endl;
}

int main()
{
    STROY();
}
