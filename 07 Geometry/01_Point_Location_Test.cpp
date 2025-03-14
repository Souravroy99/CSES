#include <bits/stdc++.h>
using namespace std;
#define ll long long

void deSTROYer()
{
    ll x1, y1, x2, y2, x3, y3 ;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;

    ll slope = (y2 - y1) * (x3 - x1) - (x2 - x1) * (y3 - y1);
    
    if(slope == 0) cout << "TOUCH";
    if(slope > 0)  cout << "RIGHT";
    if(slope < 0)  cout << "LEFT" ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        deSTROYer();
        cout << endl;
    }
}