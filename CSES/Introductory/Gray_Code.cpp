/*
Problem name: Gray Code
Algorithm or Logic: Math
Complexity: O(2^n)
Link: https://cses.fi/problemset/task/2205
More info:
More info: https://es.wikipedia.org/wiki/C%C3%B3digo_Gray 
https://www.youtube.com/watch?v=YPzfDpTRjEI&ab_channel=FastCodeDeveloper
*/

#include <bits/stdc++.h>
 
#define forn(i, n) for (ll i = 0; i < (ll)(n); i++)
#define foran(i, a, n) for (ll i = (ll)(a); i < (ll)(n); i++)
#define precise(n, k) fixed << setprecision(k) << n
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr); // cout.tie(0);
#define endl '\n'
 
using namespace std;
 
typedef unsigned long long int ll;
const ll oo = LLONG_MAX; // ll(5*1e18)+9LL; // LLONG_MIN
const double PI = 3.141592653589793;
void rwArchive();
 
const ll MAXN = 1e6 + 5;
 
char ind[9];
 
string toBinary(ll n, ll size){
    string bi = "";
    //ll len = floor(log2(n)+1);
    forn(k,size){
        if(n & (1 << k)) bi += "1";
        else bi += "0";
    }
    reverse(bi.begin(),bi.end());
    return bi;
}
 
int main()
{
    IO;
    rwArchive();
 
    int n; cin>> n;
 
    ll tam = 1, size = n;
    while(n){
        tam*=2;
        n--;
    }
 
    forn(i,tam)
    {   
        ll bi = i ^ (i >> 1);
        cout << toBinary(bi,size) << endl;
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