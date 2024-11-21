#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll modInverse(ll a, ll m) {
    ll res = 1;
    ll power = m - 2;
    while (power > 0) {
        if (power & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        power >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    ll sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0) {
        cout << 0 << '\n';
        return;
    }

    ll target = sum / 2;

    vector<ll> dp(target + 1, 0);

    dp[0] = 1;

    for(int i=1 ; i<=n ; i++)
    {
        for(int tar=target ; tar>=i ; tar--)
        {
            dp[tar] += dp[tar-i] ;
            dp[tar] %= MOD ;
        }
    }

    ll result = (dp[target] * modInverse(2, MOD)) % MOD;

    cout << result << '\n';
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
