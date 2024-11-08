#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n);

    for (auto &i : arr)
    {
        cin >> i;
    }

    sort(arr.begin(), arr.end());
    ll ans = 1e15, sum1 = 0, sum2 = 0;

    for (int i = 0; i < n; i++)
    {
        sum1 += abs(arr[n / 2] - arr[i]);
        sum2 += abs(arr[max(0, n / 2 - 1)] - arr[i]);
    }

    cout << min(sum1, sum2);
}