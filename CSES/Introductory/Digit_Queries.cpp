/*
Problem name: Digit Queries
Algorithm or Logic: Logic
Complexity: O(1)
Link: https://cses.fi/problemset/task/2431
More info:
https://www.youtube.com/watch?v=QAcH8qD9Pe0
*/

#include <bits/stdc++.h>
 
#define forn(i, n) for (ll i = 0; i < (ll)(n); i++)
#define foran(i, a, n) for (ll i = (ll)(a); i < (ll)(n); i++)
#define precise(n, k) fixed << setprecision(k) << n
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr); // cout.tie(0);
#define endl '\n'
 
using namespace std;
 
typedef unsigned long long ll;
const ll oo = LLONG_MAX; // ll(5*1e18)+9LL; // LLONG_MIN
const double PI = 3.141592653589793;
void rwArchive();
 
const ll MAXN = 1e4 + 5;
ll pow_10 [19];
 
ll k, a;
 
bool ok(ll mid, ll ini){
    //cout << ini + a * (mid - pow_10[a-1]) << endl;
    return ini + a * (mid - pow_10[a-1]) <= k;
}
 
ll bs(ll ho, ll lo, ll ini){
    ll l = ho, r = lo, ans = -1;
    while(l <= r){
        ll mid = l + ((r - l) >> 1);
        //cout << "l " << l << " mid " << mid << " r "<< r << endl;
        if(ok(mid, ini)) l = mid + 1, ans = mid;
        else r = mid-1;
    }
    return ans;
}
 
 
 
int main()
{
    IO;
    rwArchive();
 
    int q;
    cin >> q;
 
    pow_10 [0] = 1;
    foran(i,1,19){
        pow_10[i] = pow_10[i-1]*10;
        //cout << pow_10[i] << endl; 
    }
 
    while (q--)
    {
        cin >> k;
 
        ll sum = 0;
        a = 1;
        forn(i,19){
            sum += a * 9 * pow_10[i];
            if(sum >= k){
                break;
            }
            a++;
 
        }
        //cout << sum << endl;
        //cout << a << endl;
        
        ll ini = sum -  a * 9 * pow_10[a-1] + 1;
        ll num = bs(pow_10[a-1],(pow_10[a]-1), ini);
        
        //cout << ini << endl;
        //cout << num << endl;
        //cout << (ini + a * (num - pow_10[a-1]))  << endl;
 
        string numstr = to_string(num);
 
        ll pos = k - (ini + a * (num - pow_10[a-1]));
        //cout << pos << endl;
 
        cout << numstr[pos] << endl;   
        
    }
 
    return 0;
}
 
void rwArchive()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}