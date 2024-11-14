#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LINF LONG_LONG_MAX
#define LNINF LONG_LONG_MIN
#define INF INT_MAX
#define NINF INT_MIN
#define MOD 1000000007
#define TAKE(arr, n)            \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define ST set<ll>
#define UST unordered_set<ll>
#define MST multiset<ll>

void STROY()
{
    int k, n ;
    cin >> k >> n ;
    ST lights{0, k} ;
    MST dist{k} ;

    while(n--)
    {
		int pos;
		cin >> pos;

		auto it1 = lights.upper_bound(pos);
		auto it2 = it1;
		--it2;

		dist.erase(dist.find(*it1 - *it2));
		dist.insert(pos - *it2);
		dist.insert(*it1 - pos);
		lights.insert(pos);

		cout << *dist.rbegin() << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    STROY();
}