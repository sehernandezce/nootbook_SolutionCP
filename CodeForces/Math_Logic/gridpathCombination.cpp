// WF :| 戦争の芸術では、忍耐は美徳です。
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;
typedef double lf;

const int N = 4e5 + 5;
const int NMAX = 2e5+5;
const ll oo = 1e18;
const ll MOD = 955049953;
const ll phi = 638668800 - 1;

vector<ll> prime, pmod = {11,13,17,19,23,29,31};
ll isprime[30905];
ll fac[NMAX];
ll des[NMAX][10];
ll aux[10];

void criba(int n){
    for(int i = 2; i <= n; i++){
        if(isprime[i]) continue;
        prime.push_back(i);
        for(int j = i; j <= n; j+=i) isprime[j] = (ll)i;
    }
}

ll expFastItr(ll a, ll b, ll mod){
    ll x = 1LL;
    for(int i = (int)log2(b)+1; i >=0; i--){
        x *= x; x %= mod;
        if(b & (1LL << i)) x*=a;
        x %= mod;
    }
    return x;
}

ll phiEuler(ll n){
    ll ans = 0;
    for(ll i = 1; i<n; i++){
        if(__gcd(n,i) == 1) ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    /*
    int pmax = 30905;
    criba(pmax);
    ll z  = 955049953;
    //ll o = phiEuler(z);
    //cout << o << endl;
    vector<ll> factors, ex;
    ll id = 0, p = prime[id];
    while(p*p <= n){
        if(n%p == 0) factors.push_back(p);
        ll power = 0;
        while(n%p == 0){
            n/= p;
            power++;
        }
        if(power) ex.push_back(power);
        p = prime[id++];
    }
    if(n!= 1) {factors.push_back(n); ex.push_back(1);}
    */
    
    fac[0] = 1;
    for(ll i = 1; i <= 200000; i++){
        ll n = i * fac[i-1];
        //
        for(int id = 0; id<7; id++){
            ll p = pmod[id];
            while(n%p == 0){
                n/= p;
                aux[id]++;
            }
        }
        n%=MOD;
        fac[i] = n;
        for(int j = 0; j < 7; j++){
            des[i][j] = aux[j];
        }
        //
    }

    //    assert(false);
    int t; cin >> t;
    while(t--){
        ll x; cin >> x; x--;
        //cout << x << endl;
        ll num = 2*x, den = x;
        ll A = fac[num], B = fac[den];
        //cout << A << " | " << B << endl;
        for(int i = 0; i<7; i++){
            ll a = des[num][i], b = des[den][i]*2;
            //cout << a << " || " << b << endl;
            ll ax = expFastItr(pmod[i],a-b, MOD);
            A *= ax;
            A %= MOD;
        }
        B = expFastItr(((B*B)%MOD), phi, MOD);
        ll ans = (A*B)%MOD;
        cout << ans << endl;
    }

    return 0;
}