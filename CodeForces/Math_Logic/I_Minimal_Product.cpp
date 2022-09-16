/*
Algorithm or Logic: ?
Complexity: O(n)
Link: https://codeforces.com/gym/103433/problem/I
More info: 
*/

#include <bits/stdc++.h>

#define forn(i,n) for(ll i = 0; i < (ll)(n); i++)
#define foran(i,a,n) for(ll i = (ll)(a); i < (ll)(n); i++)
#define precise(n,k) fixed << setprecision(k) << n
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl '\n'

using namespace std;

typedef unsigned int ull;
typedef long long ll;
const ll oo = LLONG_MAX; //ll(5*1e18)+9LL; //  LL(5e18) + 9LL 1e18+10;
const double PI = 3.141592653589793;
void rwArchive();

const int MAXN = 1e5+5;


int main(){ 
    IO; rwArchive(); 
    
    int t;
    cin >> t;
    while(t--){
        vector <ll> aa;
        
        vector <ull> bb;
        ll r , l;
        ull n, x, y, z, b1, b2;
        cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;

        bb.push_back(b1);
        bb.push_back(b2);
        aa.push_back(((ll)(bb[0]) % (r-l+1)) + l);
        aa.push_back(((ll)(bb[1]) % (r-l+1)) + l);

        foran(i,2,n){
            bb.push_back((bb[i-2]*x + bb[i-1]*y + z));
            aa.push_back(((ll)(bb[i]) % (r-l+1)) + l);
        }
        
        ll ref = aa[0], minival = oo;
        foran(i,1,n){
            if(ref < aa[i]){
                minival = min(minival, aa[i]*ref);
            }
            ref = min(aa[i], ref);
        }

        ref = aa[n-1];
        for(ll i = n-2; i>=0; i--){
            if(ref > aa[i]){
                minival = min(minival, aa[i]*ref);
            }
            ref = max(aa[i], ref);
        }

        if(minival != oo) cout << minival << endl;
        else cout << "IMPOSSIBLE" << endl;
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