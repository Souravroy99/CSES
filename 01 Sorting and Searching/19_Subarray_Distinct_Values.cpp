#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define TAKE(arr, n)            \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]


void STROY()
{
    ll n, k ;
    cin >> n >> k ;
    vll arr(n);
    TAKE(arr, n);

    auto func = [&](ll k) -> ll
    {
        set<ll>distinct ;
        ll subArrays = 0, left=0, right=0 ;

        while(right < n)
        {
            distinct.insert(arr[right]) ;

            while(distinct.size() > k)
            {
                distinct.erase(arr[left++]) ;
            }

            subArrays += right-left+1 ;
            right++ ;
        }

        return subArrays ;
    };

    int tillK = func(k) ;
    int tillKMinusOne = func(k-1) ;

    cout << (tillK - tillKMinusOne) ;
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