/*
Problem name: A. Thor
Algorithm or Logic: Structure data
Complexity: O(q)
Link: https://codeforces.com/contest/704/problem/A
More info:
*/

#include <bits/stdc++.h>

#define forn(i,n) for(ll i = 0; i < (ll)(n); i++)
#define foran(i,a,n) for(ll i = (ll)(a); i < (ll)(n); i++)
#define precise(n,k) fixed << setprecision(k) << n
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr); //cout.tie(0);
#define endl '\n'
#define pb push_back

using namespace std;

typedef long long ll;
const ll oo = LLONG_MAX; // ll(5*1e18)+9LL; // LLONG_MIN 
const double PI = 3.141592653589793;    
void rwArchive();

const ll MAXN = 1e6+5;

vector <bool> Yes(MAXN);
unordered_map <int,queue<int>> qx;
queue <pair<int,int>> Q;

int ans=0, tot=0;

void event(int qi, int x){
    switch (qi)
    {
    case 1:
        tot++;
        Q.push({tot,x});
        qx[x].push(tot);
        ans++;
        break;
    case 2:
        ans -=qx[x].size();
        while(qx[x].size()>0)
        {   
            int k = qx[x].front();
            qx[x].pop();
            Yes[k] = true;
        }
        break;
    case 3:
        while(Q.size()>0 && Q.front().first <= x){
            int k = Q.front().first;
            int xk = Q.front().second;
            Q.pop();
            if(!Yes[k]){
                Yes[k] = true;
                qx[xk].pop();
                ans--;
            }
        }
        
        break;
    default:
        break;
    }

}

int main(){
    IO; rwArchive(); 

    int n, q; cin >> n >> q;

    while(q--){
        int tp, x;
        cin >> tp >> x;
        event(tp, x);
        cout << ans << endl;
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
