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

const ll MAXN = 1e5+10;

ll n,m;
vector<vector<bool>> marked;
unordered_map<string,bool> check;
vector<string> matches = {"DBC","DBD","DBF","LBE","LBD","LBF",
                         "DEC","DED","DEF","REC","REB","REF",
                         "UCB","UCE","UCF","LCE","LCD","LCF",
                         "UDB","UDE","UDF","RDB","RDC","RDF",
                         "UFB","UFE","UFF","RFB","RFC","RFF",
                         "DFC","DFD","DFF","LFE","LFD","LFF"};

void setup(){
    for(auto i : matches) check[i] = true;
}

void dfs(ll i, ll j, vector<string>& s){
    marked[i][j] = true;
    string aux;
    //Arriba
    if(i>0){
        aux = "U";
        aux += s[i][j];
        aux += s[i-1][j];
        if(check[aux] && !marked[i-1][j]) dfs(i-1,j,s);
    }
    //Abajo
    if(i<n-1){
        aux = "D";
        aux += s[i][j];
        aux +=s[i+1][j];
        if(check[aux] && !marked[i+1][j]) dfs(i+1,j,s);
    }
    //Derecha
    if(j<m-1){
        aux = "R";
        aux += s[i][j];
        aux += s[i][j+1];
        if(check[aux] && !marked[i][j+1]) dfs(i,j+1,s);
    }
    //Izquierda
    if(j>0){
        aux = "L";
        aux += s[i][j];
        aux +=s[i][j-1];
        if(check[aux] && !marked[i][j-1]) dfs(i,j-1,s);
    }
}

int main(){
    IO;
    ll z,ans;
    setup();
    cin>>z;
    while(z--){
        cin>>n>>m;
        vector<string> s (n);
        marked.assign(n,vector<bool>(m,false));
        forn(i,n) cin>>s[i];
        //Marcar vacios
        forn(i,n){
            forn(j,m){
                if(s[i][j]=='A') marked[i][j] = true;
            }
        }
        //dfs
        ans = 0;
        forn(i,n){
            forn(j,m){
                if(!marked[i][j]){
                    dfs(i,j,s);
                    ans++;
                }
            }
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
