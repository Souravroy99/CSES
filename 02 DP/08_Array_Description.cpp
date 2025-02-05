#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define vll vector<ll>
#define TAKE(arr, n)            \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]



/*
ll dp[100001][201];
ll memoI(vll &arr, int idx, int n, int m)
{
    if (idx == n)
        return 1;
    if (idx > 0 && arr[idx] != 0 && (abs(arr[idx - 1] - arr[idx]) > 1))
        return 0;

    if (dp[idx][arr[max(0, idx - 1)]] != -1)
        return dp[idx][arr[max(0, idx - 1)]];

    ll dec = 0, neu = 0, inc = 0, justSkip = 0;

    if (arr[idx] == 0)
    {
        if (idx == 0)
        {
            for (int num = 1; num <= m; num++)
            {
                arr[idx] = num;
                inc = (inc % MOD + memoI(arr, idx + 1, n, m) % MOD) % MOD;
            }
        }
        else
        {
            if (arr[idx - 1] >= 2 && arr[idx - 1] <= m)
            {
                arr[idx] = arr[idx - 1] - 1;
                dec = memoI(arr, idx + 1, n, m);
            }

            if (arr[idx - 1] >= 1 && arr[idx - 1] <= m)
            {
                arr[idx] = arr[idx - 1];
                neu = memoI(arr, idx + 1, n, m);
            }

            if (arr[idx - 1] >= 1 && arr[idx - 1] < m)
            {
                arr[idx] = arr[idx - 1] + 1;
                inc = memoI(arr, idx + 1, n, m);
            }
        }

        arr[idx] = 0;
    }
    else
    {
        justSkip = memoI(arr, idx + 1, n, m);
    }

    return dp[idx][arr[max(0, idx - 1)]] = max((dec % MOD + neu % MOD + inc % MOD) % MOD, justSkip % MOD);
}
memset(dp, -1, sizeof dp);
cout << memoI(arr, 0, n, m);
*/




void STROY()
{
    int n, m;
    cin >> n >> m;
    vll arr(n);
    TAKE(arr, n);

    vector<vector<ll>>dpp(n, vll(m + 2, 0));


    // Base Case
    for (int i = 1; i <= m; i++) {
        if(arr[0] == i || arr[0] == 0)
            dpp[0][i] = 1 ;
    }


    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dpp[i][j] = (dpp[i - 1][j - 1] + dpp[i - 1][j] + dpp[i - 1][j + 1]) % MOD;
            }
        }
        else
        {
            dpp[i][arr[i]] = (dpp[i - 1][arr[i] - 1] + dpp[i - 1][arr[i]] + dpp[i - 1][arr[i] + 1]) % MOD;
        }
    }

    ll result = 0;
    for (int num = 1; num <= m; num++) {
        result = (result + dpp[n - 1][num]) % MOD;
    }

    cout << result << endl;
}

int main() {
    STROY();
}