#include<bits/stdc++.h>
using namespace std ;

void binary_lifting(int n, vector<vector<int>>&up)
{   
    for(int boss=1 ; boss<=log2(n) ; boss++)
    {
        for(int emp=1 ; emp<n ; emp++)
        {
            if(up[emp][boss-1] == -1) continue ;

            up[emp][boss] = up[up[emp][boss-1]][boss-1] ;
        }
    }
}

int main()
{
    int n, q ;
    cin >> n >> q ;

    vector<vector<int>>up(n+1, vector<int>(log2(n)+1, -1)) ;

    for(int emp=1 ; emp<=n-1 ; emp++)
    {
        int boss ;
        cin >> boss ;
        --boss ;

        up[emp][0] = boss ;
    }

    binary_lifting(n, up) ;


    vector<int>kth_ancestor ;
    while(q--)
    {
        int node, level ;
        cin >> node >> level ;
        node-- ;
  
        while(level != 0 && node != -1)
        {
            node = up[node][log2(level & (~(level-1)))] ;
            level &= level-1 ;
        }

        kth_ancestor.push_back(node) ;
    }

    for(auto it: kth_ancestor) {
        cout << (it == -1 ? it : ++it) << " " ;
    }
}