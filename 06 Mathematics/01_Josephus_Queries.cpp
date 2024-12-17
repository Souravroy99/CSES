#include<bits/stdc++.h>
using namespace std ;

// Approach 1 : TC = O(N*LogN) & SC = O(N) 
void Josephus(int n) 
{
    set<int>st ;
    for(int i=1 ; i<=n ; i++) st.insert(i) ;

    auto it = st.begin();

    while (!st.empty())
    {
        if(it == st.end()) it = st.begin() ;
        it++ ;
        if(it == st.end()) it = st.begin() ;

        cout << *it << " " ;
        st.erase(it++) ;
    }
}


// Approach 2 : TC = O(LogN) & SC = O(LogN) 
int Josephus_best(int n, int kth)
{
    if(n == 1) return 1 ;
    if(kth <= (n+1)/2)
    {
        if(2*kth > n) return (2*kth)%n ;
        return 2*kth ;
    }

    int temp = Josephus_best(n/2, kth-(n+1)/2) ;

    if(n&1) return 2*temp+1 ;
    return 2*temp-1 ; 
}

int main() 
{
    int n ;
    cin >> n ;

    // Josephus(n) ;

    for(int kth=1 ; kth<=n ; kth++) // TC = O(N*LogN)
    {
        cout << Josephus_best(n, kth) << " " ;
    }
}