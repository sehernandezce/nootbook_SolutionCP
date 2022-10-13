/*
Problem name: Tower of Hanoi
Algorithm or Logic: Logic
Complexity: O(2^n)
Link: https://cses.fi/problemset/task/2165
More info:
https://www.youtube.com/watch?v=rf6uf3jNjbo
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
 
const ll MAXN = 1e4 + 5;
 
void myprint(int start, int end){
    cout << start <<" " << end << endl;
}
 
void hanoi_reloco_papi_reloco(int n, int from, int to){
    if(n == 1){ 
        myprint(from,to);
        return;
    }
    
    int aux = 6 - (from + to);
    hanoi_reloco_papi_reloco(n-1,from,aux);
    myprint(from, to);
    hanoi_reloco_papi_reloco(n-1,aux,to);
}
 
int main()
{
    IO;
    rwArchive();
 
    int n; cin >> n;
 
    cout << (pow(2,n) - 1) << endl;
    hanoi_reloco_papi_reloco(n,1,3);
 
    return 0;
}
 
void rwArchive()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}