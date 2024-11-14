#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LINF LONG_LONG_MAX
#define LNINF LONG_LONG_MIN
#define INF INT_MAX
#define NINF INT_MIN
#define MOD 1000000007
#define vll vector<ll>
#define vvll vector<vll>
#define pb push_back
#define pr pair<ll, ll>
#define vp vector<pair<ll, ll>>
#define vs vector<string>
#define fr(i, a, n) for (ll i = a; i < n; i++)
#define rfr(i, a, n) for (ll i = n - 1; i >= a; i--)

#define TAKE(arr, n)            \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define ALL(arr) (arr).begin(), (arr).end()
#define SORTA(arr, n) sort(arr, arr + n)
#define SORT(arr) sort(arr.begin(), arr.end())
#define RSORT(arr) sort(arr.rbegin(), arr.rend())
#define SUM(arr) accumulate(arr.begin(), arr.end(), 0LL)
#define MAX(arr) *max_element(begin(arr), end(arr))
#define MIN(arr) *min_element(begin(arr), end(arr))
#define MAP map<ll, ll>
#define UMAP unordered_map<ll, ll>
#define ST set<ll>
#define UST unordered_set<ll>
#define pn cout << "NO" << "\n"
#define py cout << "YES" << '\n'
#define pmo cout << -1
#define imp cout << 1  
#define nl cout << '\n'

void STROY()
{
    int n ;
    cin >> n ;
    vll arr(n) ;
    TAKE(arr, n) ;
    int mx=1 ;
    MAP mp ;

    int left=0, right=0 ;
    while(right < n)
    {
        mp[arr[right]]++ ;

        while(mp[arr[right]] > 1) 
        {
            mp[arr[left]]-- ;
            if(mp[arr[left]] == 0) {
                mp.erase(arr[left]) ;
            }
            left++ ;
        }

        ++right ;
        mx = max(mx, right-left) ;
    }

    cout << mx ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    STROY();
}