/*
Problem name: Restaurant Customers
Algorithm or Logic: Logic ans sort
Complexity: O(n)
Link: https://cses.fi/problemset/task/1619/
More info:
https://www.youtube.com/watch?v=O9Sptr-RdRo&ab_channel=ARSLONGAVITABREVIS
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
void USACO();
 
const ll MAXN = 1e6 + 5;
vector <pair <int,int>> customers;
 
 
int main()
{
    IO;
    rwArchive(); // USACO();

    int n; cin >> n;

    forn(i,n){
        int ax, bx; cin >> ax >> bx;
        customers.push_back({ax,1});
        customers.push_back({bx,-1});
    }

    sort(customers.begin(),customers.end());

    int acum = 0, ans = 0;
    for(auto e: customers){
        acum += e.second;
        ans = max(acum, ans);
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

void USACO()
{
 
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
}
 
// By Seishi