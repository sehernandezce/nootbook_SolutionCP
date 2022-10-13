/*
Problem name: Trailing Zeros
Algorithm or Logic: Math
Complexity: O(log(n))
Link: https://cses.fi/problemset/task/1618
More info:
2 * 5 = 10 but # of 5 <  # of 2 then we count the number of numbers divisible by 5.
With tutorial: https://stackoverflow.com/questions/61283387/write-a-program-that-will-calculate-the-number-of-trailing-zeros-in-a-factorial
https://www.youtube.com/watch?v=eCRMp5hUHQM&ab_channel=FastCodeDeveloper
*/

#include <bits/stdc++.h>
 
#define forn(i, n) for (ll i = 0; i < (ll)(n); i++)
#define foran(i, a, n) for (ll i = (ll)(a); i < (ll)(n); i++)
#define precise(n, k) fixed << setprecision(k) << n
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr); // cout.tie(0);
#define endl '\n'
 
using namespace std;
 
typedef unsigned long long ll;
const ll oo = LLONG_MAX; // ll(5*1e18)+9LL; // LLONG_MIN
const double PI = 3.141592653589793;
void rwArchive();
 
const ll MAXN = 2 * 1e5 + 5;
ll aa[MAXN];
ll mod = 1e9 + 7;
 
int main()
{
    IO;
    rwArchive();
 
    ll n;
    cin >> n;
 
    // The number of numbers divisible by 5 between 1 and n
    ll prime = 5, ans = 0;
    while (n)
    {
        n /= prime;
        ans += n;
    }
    cout << ans << endl;
    return 0;
}
 
void rwArchive()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}