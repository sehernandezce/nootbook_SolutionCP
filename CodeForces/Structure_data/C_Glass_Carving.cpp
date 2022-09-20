/*
Problem name: C. Glass Carving
Algorithm or Logic: Structure data
Complexity: O(n * log n)
Link: https://codeforces.com/contest/527/problem/C
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

int mw [MAXN];
int mh [MAXN];
set <int> hh;
set <int> ww;

int main(){
    IO; rwArchive(); 

    int w,h,n;
    cin >> w >> h >> n;
    mh[h] = mw[w] = 1;
    hh.insert(0);
    hh.insert(h);
    ww.insert(0);
    ww.insert(w);

    while(n--){
        string c;
        int xy;
        cin >> c >> xy;

        if(c.compare("H") == 0){
            auto itr = hh.upper_bound(xy);
            auto itr2 = itr;
            itr2 --;
            int mx = *itr, mx2 = *itr2;
            
            mh[mx - mx2]--;
            mh[mx - xy]++;
            mh[xy - mx2]++;
            hh.insert(xy);
        }else{
            auto itr = ww.upper_bound(xy);
            auto itr2 = itr;
            itr2 --;
            int mx = *itr, mx2 = *itr2;
            mw[mx - mx2]--;
            mw[mx - xy]++;
            mw[xy - mx2]++;
            ww.insert(xy);
        }

        while(mh[h] == 0) h--;
        while(mw[w] == 0) w--;
        //cout << h << " " << w << endl;
        cout << 1LL*h*w << endl;
    }

    
    return 0;
}

void rwArchive(){
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin); 
       freopen("output.txt", "w", stdout);  
    #endif
}

//By Seishi