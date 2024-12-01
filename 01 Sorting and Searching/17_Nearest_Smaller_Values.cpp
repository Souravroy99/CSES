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
    ll n ;
    cin >> n ;
    vll arr(n);
    TAKE(arr, n);

    stack<pair<int,int>>st ; // Ele, Idx
    vector<int>leftSmaller ;

    for(int i=0 ; i<n ; i++)
    {
        while(!st.empty() && st.top().first >= arr[i]) st.pop() ;

        if(st.empty()) leftSmaller.push_back(0) ;
        else leftSmaller.push_back(st.top().second) ;

        st.push({arr[i], i+1}) ;
    }

    for(auto it : leftSmaller) {
        cout << it << " " ;
    }
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