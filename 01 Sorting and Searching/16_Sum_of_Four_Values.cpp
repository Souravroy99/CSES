#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define TAKE(arr, n)            \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]

//                                  TC = O(N^2 * LogN) & SC = O(N)

void STROY()
{
    ll n, sum;
    cin >> n >> sum;
    vll arr(n);
    TAKE(arr, n);

    bool isDone = false;

    set<vector<ll>> twoSum;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            twoSum.insert({arr[j] + arr[i], j + 1, i + 1});
        }

        for (int k = i + 2; k < n; k++)
        {
            ll req = sum - (arr[i + 1] + arr[k]);

            if (twoSum.lower_bound({req, -1, -1}) != twoSum.end() && (*twoSum.lower_bound({req, -1, -1}))[0] == req)
            {
                isDone = true;
                auto it = *twoSum.lower_bound({req, -1, -1});

                cout << it[1] << " " << it[2] << " " << i + 2 << " " << k + 1;
                goto jump;
            }
        }
    }

jump:
    if (isDone == false)
        cout << "IMPOSSIBLE";
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