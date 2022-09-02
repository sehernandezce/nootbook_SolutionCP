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
#define foran(i,a,n) for(ll i = a; i < (ll)(n); i++)
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define precise(n,k) fixed << setprecision(k) << n
#define endl '\n'
#define X real () //Variables
#define Y imag ()
#define MAX LLONG_MAX
#define MIN LLONG_MIN

using namespace std;

typedef int ll;
typedef complex<ll> P;

using ii=pair<ll,ll>;
using iii=tuple<ll,ll,ll>;

const ll oo = 1e18+10; // 1e9+10;
const double PI = 3.141592653589793;

void rwArchive();
void tests();
//  BEGIN

const ll MAXN = 1e5+10;

int main(){
    IO;
    ll ans,n;
    string s;
    while(cin>>s){
        ans = 0;
        n = stoi(s.substr(2));
        for(ll i=n+1;i<=n*2;++i){
            if((i*n)%(i-n)==0)ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}

//  END
void rwArchive(){
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif
}
/*
void tests(){
    ll t;
    cin >> t;
    forn(i,t) solv();
}
*/
//made by AI_Algorimth
