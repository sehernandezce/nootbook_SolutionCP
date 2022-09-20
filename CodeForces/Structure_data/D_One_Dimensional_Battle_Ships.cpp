/*
Problem name: D. One-Dimensional Battle Ships
Algorithm or Logic: Structure data
Complexity: O(m * log m)
Link: https://codeforces.com/contest/567/problem/D
More info:
*/

#include <bits/stdc++.h>

#define forn(i,n) for(ll i = 0; i < (ll)(n); i++)
#define foran(i,a,n) for(ll i = (ll)(a); i < (ll)(n); i++)
#define precise(n,k) fixed << setprecision(k) << n
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr); //cout.tie(0);
#define endl '\n'

using namespace std;

typedef long long ll;
const ll oo = LLONG_MAX; // ll(5*1e18)+9LL; // LLONG_MIN 
const double PI = 3.141592653589793;
void rwArchive();

const ll MAXN = 2*1e5+5;

set <int> lo;
set <int> hi;
int n, k, a, m, contb=0;

int numb(int lo, int hi){
    return (hi-lo) / (a+1);
}

int main(){
    IO; rwArchive();    

    cin >> n >> k >> a >> m;

    lo.insert(0); hi.insert(0);
    lo.insert(-(n+1)); hi.insert(n+1); 
    contb+=numb(0,n+1);

    foran(i,1,m+1){
        int mi; cin >> mi;
        int l = -*(lo.upper_bound(-mi));
        int h = *hi.upper_bound(mi);
        
        contb-=numb(l,h);
        contb+=numb(mi,h);
        contb+=numb(l,mi);

        lo.insert(-mi); hi.insert(mi);

        if(contb < k){
            cout << i << endl;
            return 0;
        }

    }

    cout << -1 << endl;

    return 0;
}

void rwArchive(){
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin); 
       freopen("output.txt", "w", stdout);  
    #endif
}

//By Seishi