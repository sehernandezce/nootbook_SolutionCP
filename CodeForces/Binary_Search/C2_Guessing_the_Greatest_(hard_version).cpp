/*
Problem name: C2. Guessing the Greatest (hard version)
Algorithm or Logic: Binary search
Complexity: O(2 + log(n))
Link: https://codeforces.com/contest/1486/problem/C2
More info: 
*/
#include <bits/stdc++.h>

#define fs first // struct
#define sc second
#define mt make_tuple
#define pb push_back
#define all(s) s.begin(),s.end() 
#define allr(s) s.rbegin(),s.rend()
#define sz size
#define len length
#define forn(i,n) for(ll i = 0; i < (ll)(n); i++) // for, input, output
#define foran(i,a,n) for(ll i = (ll)(a); i < (ll)(n); i++)
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define precise(n,k) fixed << setprecision(k) << n
#define endl '\n'
#define X real () //Variables
#define Y imag ()
#define MAX LLONG_MAX
#define MIN LLONG_MIN

using namespace std;

typedef long long ll;
typedef double dd; 
typedef complex<ll> cc;

using ii=pair<ll,ll>;
using iii=tuple<ll,ll,ll>;

const ll oo = 1e18+10; // 1e9+10;
const dd PI = 3.141592653589793;

void rwArchive();
//  BEGIN
const ll MAXN = 1e4+5;

ll query(ll l , ll r){
    cout << "? " << l << " " << r <<endl;
    cout.flush();

    ll ansq;
    cin >> ansq;
    return ansq;
}

int main(){
    IO; 
    //rwArchive();
    //Begin
    ll n;
    cin >> n;
    ll l = 1, r = n;
    ll smax = query(l,r);

    if(smax == 1 || smax != query(1,smax)){
        l = smax, r = n;
        while(r-l > 1){
            ll mid = l + ((r-l) >> 1);
            if(smax == query(smax, mid)){
                r = mid;
            }else{
                l = mid;
            }
        }
        cout << "! " << r <<endl;
        cout.flush();
    }else{
        l = 1, r = smax;
        while(r-l > 1){
            ll mid = l + ((r-l) >> 1);
            if(smax == query(mid, smax)){
                l = mid;
            }else{
                r = mid;
            }
        }
        cout << "! " << l <<endl;
        cout.flush();

    }
       
    //End
    return 0;
}

//  END
void rwArchive(){
    #ifndef ONLINE_JUDGE  
       freopen("input.txt", "r", stdin); 
       freopen("output.txt", "w", stdout);  
    #endif
}
