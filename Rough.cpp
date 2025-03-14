#include <bits/stdc++.h>
using namespace std ;

int main()
{
    vector<int>v = {1,2,3,4,5} ;

    vector<int>arr(v.begin(), v.begin()+2) ;

    for(auto it : arr) cout << it << " " ;

}