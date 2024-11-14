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

        timings.push_back({start, +1});
        timings.push_back({end, -1});
    }

    sort(timings.begin(), timings.end()) ;
    int maxCustomers = 0, peopleCnt=0 ;

    for(auto it : timings) {
        peopleCnt += it.second ;
        maxCustomers = max(maxCustomers, peopleCnt) ;
    }

    cout << maxCustomers ;
}