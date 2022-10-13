/*
Problem name: Apple Division
Algorithm or Logic: Logic
Complexity: O(2^n)
Link: https://cses.fi/problemset/task/1623
More info:
https://www.youtube.com/watch?v=raGn3saVfa8&ab_channel=ARSLONGAVITABREVIS

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
 
ll aa[25];
 
int main()
{
    IO;
    rwArchive();
    ll n;
    cin >> n;
 
    forn(i, n)
    {
        cin >> aa[i];
    }
 
    ll ans = oo;
 
    for (ll mask = 0; mask < (1 << n); mask++)
    {
        ll sumA = 0;
        ll sumB = 0;
        for (ll i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                sumA += aa[i];
            else
                sumB += aa[i];
        }
        ans = min(ans, abs(sumA - sumB));
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