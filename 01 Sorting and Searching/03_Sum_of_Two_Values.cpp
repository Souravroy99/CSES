#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n, target ;
    cin >> n >> target ;
    vector<pair<int,int>>arr(n) ;

    for(int i=0 ; i<n ; i++) {
        int x; cin >> x ;
        arr[i] = {x, i+1} ;
    }


    sort(arr.begin(), arr.end()) ;
    int i=0, j=n-1 ;
    bool flag = true ;

    while(i<j)
    {
        int sum = arr[i].first + arr[j].first ;
        if(sum == target)
        {
            cout << arr[i].second << " " << arr[j].second ;
            flag = false ;
            break ;
        }
        else if(sum > target) j-- ;
        else i++ ;
    }

    if(flag) cout << "IMPOSSIBLE";
}