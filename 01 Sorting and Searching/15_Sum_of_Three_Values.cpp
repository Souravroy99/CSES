#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define TAKE(arr, n)            \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define SORT(arr) sort(arr.begin(), arr.end())


void STROY()
{
    ll n, target;
    cin >> n >> target;
    vll arr(n);
    TAKE(arr, n);

    vector<pair<int,int>> vec ;
    for(int i=0 ; i<n ; i++) vec.push_back({arr[i], i+1}) ;
    SORT(vec) ;

    for(int i=0 ; i<n-2 ; i++)
    {
        int left=i+1, right=n-1 ;
        while(left < right)
        {
            int sum = vec[i].first+vec[left].first+vec[right].first ;

            if(sum == target)
            {
                cout << vec[i].second << " " << vec[left].second << " " << vec[right].second ;
                return ;
            }
            else if(sum < target) left++ ;
            else right-- ;
        }
    }

    cout << "IMPOSSIBLE" ;
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