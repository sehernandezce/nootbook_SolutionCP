/*
Problem name: K - Right Expansion Of The Mind
Algorithm or Logic: Bitmask y string
Complexity: O(n)
Link: https://codeforces.com/gym/103433/problem/K
More info:
//https://neerc.ifmo.ru/school/archive/2018-2019/ru-olymp-team-russia-2018-presentation.pdf
//https://codeforces.com/contest/1090/submission/46797474
*/

#include <bits/stdc++.h>
#include <unordered_map>

#define forn(i,n) for(ll i = 0; i < (ll)(n); i++)
#define foran(i,a,n) for(ll i = (ll)(a); i < (ll)(n); i++)
#define precise(n,k) fixed << setprecision(k) << n
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(0);
#define endl '\n'
#define pb push_back
#define sc second
#define popb pop_back()

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const ll oo = LLONG_MAX; 
const double PI = 3.141592653589793;
void rwArchive();

const int MAXN = 2*1e5+5;
map <pair<string,int>, vector<int>> ump;

void f(string &s, string &t, int id){
    int maskt = 0;
    forn(i, t.size()){ // Mask of character a = 2^0 -> 1 ; b = 2^2 -> 10
        maskt |= (1 << (t[i] - 'a')); // put each value together
    }

    while(s.size()){ 
        int masksi = (1 << (s[s.size()-1] - 'a'));
        if( maskt & masksi){ // if the letter s[i] is in the word t it takes it out of S
            s.popb;
            continue;
        }
        break;
    }

    ump[{s,maskt}].pb(id);
}

int main(){ 
    IO; rwArchive(); 

    int n; cin >> n;
    string s,t;

    foran(i,1,n+1){
        cin >> s >> t;
        f(s,t,i);
    }

    cout << ump.size() << endl;
    for(auto all: ump){
        cout << all.sc.size() << " ";    
        forn(i,all.sc.size()){
            cout << all.sc[i];
            if(ull(i+1) < all.sc.size()) cout << " ";
        }
        cout << endl;   
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
