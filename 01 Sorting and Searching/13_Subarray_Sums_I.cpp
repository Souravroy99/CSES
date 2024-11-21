#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long left = 0, right = 0, cnt = 0, sum = 0;

    while (right < n)
    {
        sum += arr[right];
        while (sum > m)
        {
            sum -= arr[left++]--;
        }
        if (sum == m)
            cnt++;
        right++;
    }
    cout << cnt << endl;
}