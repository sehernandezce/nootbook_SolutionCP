/*
Problem name: 12207 - That is Your Queue
Algorithm or Logic: Structure data Queue
Complexity: O(n)
Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3359
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


int solv(){
    //ll n, ans = 0;
    //cin >> n;
    ll t = 1;
    while(1){
        ll p,c;
        cin >> p >> c;
        if(p == 0 || c == 0) return 0;
        cout << "Case "<< t <<":" <<endl; 
        queue <ll> qq,qqq;

        foran(i,1,min(p+1,(ll)1000)) qq.push(i);

        while(c--){
            char c;
            cin >> c;
            if(c == 'N'){
                ll num = qq.front();
                qq.pop();
                cout << num;
                cout << endl; 
                if(num <= 1000) qq.push(num);
            }else if(c  == 'E'){
                ll k;
                cin >> k;            
                    ll head = k;
                    while(qq.size() > 0){
                        ll num = qq.front();
                        qq.pop();
                        if(num == k) head = num;
                        else qqq.push(num);                        
                    }
                    
                    qq.push(head);
                    while(qqq.size()>0){
                        ll num = qqq.front();
                        qqq.pop();
                        qq.push(num);
                    }
                    
                
            }            
        }
        t++;
    }

    //cout << endl;   
    return 0; 
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