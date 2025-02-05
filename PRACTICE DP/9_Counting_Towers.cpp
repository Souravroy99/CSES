#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

const int N = 1000001 ;
ll dp_0[N], dp_1[N] ;

void pre_calculation()
{
    // dp_0[i] --> How many ways end without partition till ith index
    // dp_1[i] --> How many ways end with partition till ith index
    
    dp_0[0] = dp_1[0] = 1 ;

    for (int i = 1; i < N; i++)
    {
        dp_0[i] = (dp_0[i - 1] + dp_0[i - 1] + dp_1[i - 1]) % mod;
        dp_1[i] = (dp_0[i - 1] + dp_1[i - 1] + dp_1[i - 1] + dp_1[i - 1] + dp_1[i - 1]) % mod;
    }
}

int main()
{
    int t;
    cin >> t;

    pre_calculation() ;

    while (t--)
    {

        int n;
        cin >> n;

        int number_of_ways_to_arrange = (dp_0[n - 1] + dp_1[n - 1])%mod ;
        cout << number_of_ways_to_arrange << endl ;
    }
}