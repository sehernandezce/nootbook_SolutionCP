/*
Problem name: 10110 - Light, more light
Algorithm or Logic: Raiz cuadrada perfecta
Complexity: O(1)
Link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1051
More info: https://medium.com/consol/light-more-light-uva-10110-8adfbe86a68f
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
#define foran(i,a,n) for(ll i = a; i < (ll)(n); i++)
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define precise(n,k) fixed << setprecision(k) << n
#define endl '\n'
#define X real () //Variables
#define Y imag ()
#define MAX LLONG_MAX
#define MIN LLONG_MIN

using namespace std;

typedef long long ll;
typedef complex<ll> P;

using ii=pair<ll,ll>;
using iii=tuple<ll,ll,ll>;

const ll oo = 1e18+10; // 1e9+10;
const double PI = 3.141592653589793;

void rwArchive();
void tests();
//  BEGIN

const ll MAXN = 1e3+10;

bool isSqrtPerfect(ll n){
    double n2 = sqrt(n);
    return (n2 - floor(n2) == 0);
}

void solv(){
    ll n; // k % c == 1
    while(1){
         cin >> n;
         if(n == 0) return;

        if(isSqrtPerfect(n)) cout << "yes";
        else  cout << "no";
       cout << endl; 
    }
    
     
    //cout << endl;    
}

int main(){
    IO;
    rwArchive();  
    //Begin 

    solv(); 
    //tests();
    

    return 0;
}

//  END
void rwArchive(){
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif
}

void tests(){
    ll t;   
    cin >> t;
    forn(i,t) solv();
}

//made by Sebastian