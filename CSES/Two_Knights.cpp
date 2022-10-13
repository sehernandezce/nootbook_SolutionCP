/*
Problem name: Two Knights
Algorithm or Logic: Combinatorics
Complexity: O(1)
Link: https://cses.fi/problemset/task/1072
More info: https://www.youtube.com/watch?v=RlpM5N-ttcU&ab_channel=SaiAnishMalla

Combinatoria sin repeticion - casillas donde se atacan caballos 
(Son casillas de 2 x 3 o 3 x 2)
((k^4 - k^2) / 2)  - 4 * (k-2) * (k-1)
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
 
    int n; cin >> n;
 
    foran(k,1,n+1){
        ll combr_n = (pow(k, 4) - pow(k,2)) / 2;
        ll cas_attack = 4*(k - 2)* (k - 1);
        ll ans = combr_n - cas_attack;
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
