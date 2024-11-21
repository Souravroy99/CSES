#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<long long,int>mp ;
    mp[0] = 1 ;
    long long sum = 0, cnt=0 ;

    for(int i=0 ; i<n ; i++)
    {
        sum += arr[i] ;
        long long req = sum-m ;

        cnt += mp[req] ;
        mp[sum]++ ;
    }

    cout << cnt << endl;
}