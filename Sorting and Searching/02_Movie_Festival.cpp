#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n ;
    cin >> n ;

    vector<pair<int,int>>timings;
    for(int i=0 ; i<n ; i++) {
        int start, end; 
        cin >> start >> end ;

        timings.push_back({start, end});
    }
    sort(timings.begin(), timings.end()) ;

    int cnt=0, prevEnd = timings[0].second, idx=1 ;

    while(idx < n)
    {
        int start = timings[idx].first ;
        int end = timings[idx].second ;

        if(start < prevEnd) prevEnd = min(prevEnd, end) ;
        else {
            cnt++ ;
            prevEnd = end ;
        }

        idx++ ;
    }

    cout << ++cnt ;
}