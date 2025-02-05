#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PINF INT_MAX
#define nl cout << '\n'


/*
ll dp[501][501];

int memoI(int a, int b)
{
    if (a == b)
        return 0; // Square
    if (dp[a][b] != -1)
        return dp[a][b];

    int cut = PINF;

    for (int i = 1; i < a; i++)
        cut = min(cut, 1 + memoI(i, b) + memoI(a - i, b));

    for (int j = 1; j < b; j++)
        cut = min(cut, 1 + memoI(a, j) + memoI(a, b - j));

    return dp[a][b] = cut;
}
memset(dp, -1, sizeof dp);
cout << memoI(a, b);
*/

void STROY()
{
    int a, b;
    cin >> a >> b;

    int dpp[a + 1][b + 1];
    memset(dpp, 0, sizeof dpp);

    for (int len = 1; len <= a; len++)
    {
        for (int wid = 1; wid <= b; wid++)
        {
            int cut = PINF;
            if(len == wid) cut = 0 ;

            for (int l = 1; l < len; l++)
            {
                cut = min(cut, 1 + dpp[l][wid] + dpp[len - l][wid]);
            }

            for (int w = 1; w < wid; w++)
            {
                cut = min(cut, 1 + dpp[len][w] + dpp[len][wid - w]);
            }

            dpp[len][wid] = cut ;
        }
    }

    cout << dpp[a][b];
}

int main()
{
    int t = 1;
    // cin >> t;

    while (t--)
    {
        STROY();
        nl;
    }
}
