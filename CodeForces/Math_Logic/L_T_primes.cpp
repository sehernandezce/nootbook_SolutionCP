/*
Algorithm or Logic: T-prime | Sieve of Eratosthenes
Complexity:  O(n*log(log n)*log n)
Link: https://codeforces.com/group/2Cle9xU7oR/contest/388771/problem/L
More info: T-prime is the square of a prime number
*/

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define endl '\n'

typedef long long ll;

const ll MAXN=1e6+10;
set <ll> st_primoal2;

vector <ll> prime;
void prim(ll n){ // Sieve of Eratosthenes
    ll num[n+5];
     num[0]=-1;
     num[1]=-1;
     for(ll i=2; i<=n; i++) num[i]=i;

     ll i=2;
     while(i<=n){ // primes until n
        if(num[i]!=-1){
            prime.PB(i);
            st_primoal2.insert(i*i); // Prime^2
            for(ll j=i; j<= n/i; j++){
                num[i*j]=-1;
            }
        }
        i++;
     }
}

void solv(){
    ll x;
    cin >> x;

    if(st_primoal2.find(x)!=st_primoal2.end()) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // input
    int n;
    cin >> n;
    prim(MAXN);
    for(int i=0; i<n; i++) solv();
    
    return 0;
}