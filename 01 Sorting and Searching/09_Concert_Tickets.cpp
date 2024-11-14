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
#define TAKE(arr, n)            \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define ST set<ll>
#define UST unordered_set<ll>
#define MST multiset<ll>

void STROY()
{
    int n, m ;
    cin >> n >> m ;
    MST price ;

    for(int i=0; i<n ; i++) {
        int p ;
        cin >> p ;
        price.insert(-p) ;
    }

    while(m--)
    {
        int cost ;
        cin >> cost ;
        auto it = price.lower_bound(-cost) ;

        if(it == price.end()) cout << -1 ;
        else {
            cout << (*it)*-1 ;
            price.erase(it) ;
        }
        
        cout << endl ;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    STROY();
}