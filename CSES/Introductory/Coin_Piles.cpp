/*
Problem name: Coin Piles
Algorithm or Logic: Math
Complexity: O(1)
Link: https://cses.fi/problemset/task/1754
More info:
Only positive solutions of the system are valid. 
a = 2x + y  ; b = x + 2y
https://www.youtube.com/watch?v=_k8rmGHbnuE&ab_channel=SaiAnishMalla
*/

#include <bits/stdc++.h>
 
#define forn(i, n) for (ll i = 0; i < (ll)(n); i++)
#define foran(i, a, n) for (ll i = (ll)(a); i < (ll)(n); i++)
#define precise(n, k) fixed << setprecision(k) << n
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr); // cout.tie(0);
#define endl '\n'
 
using namespace std;
 
typedef long long ll;
const ll oo = LLONG_MAX; // ll(5*1e18)+9LL; // LLONG_MIN
const double PI = 3.141592653589793;
void rwArchive();
 
const ll MAXN = 1e6 + 5;
 
int main()
{
    IO;
    rwArchive();
 
    ll t;
    cin >> t;
 
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
 
        string ans;
 
        if((2*a - b) >= 0 && (2*a - b) % 3 == 0 && (2*b - a) >= 0 && (2*b - a) % 3 == 0) ans = "YES";
        else ans = "NO";
 
        cout << ans << endl;
    }
 
    return 0;
}
 
void rwArchive()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}