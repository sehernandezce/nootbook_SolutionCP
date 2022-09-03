/*
Problem name: J. Shortest Path!
Algorithm or Logic: Geometry
Complexity: O(1)
Link: https://codeforces.com/group/oG2KRkVb92/contest/395241/problem/J
More info: https://www.youtube.com/watch?v=GrURR5wm108&ab_channel=educale.com
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

dd distance (dd x,  dd y){
    return (sqrt(x*x + y*y));
}

int main(){
    IO; 
    rwArchive();
    //Begin

    ll t;
    cin >> t;
    dd a,b,c,x;
        
    while (t--){
        cin >> a >> b >> c >> x;

        x/=100;
        dd ida = distance(a,b+2.0*c); 
        dd vuelta = distance(a*x,b*x);
        x=1-x;
        vuelta += distance(a*x,b*x + 2.0*c);
        cout << precise(ida+vuelta,9) << endl;
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

//made by Sebastian

//
/* Attempt 1
        x/=100;
     
        dd dis1 = sqrt((a*a)/pow((b+2*c), 2) + 1) * (b+2*c); // Distance House to river to grandmother // a ^ b = %f\n", pow (a, b)

        dd dis2 = sqrt(a*a + b*b) * x; // Distance Grandmother to house x%

        dd k = ((a-a*x) * (c+b-b*x)) / (2*c + b - b*x);
        dd d3 = sqrt(pow(c+b-b*x,2) +pow(k,2));
        dd d4 = sqrt(pow(c,2) + pow(a-a*x - k,2));
        dd dis3 = d3 + d4; //Distance x% to river to house

        dd distance = dis1 + dis2 + dis3;
        
        cout << precise(distance,9) << endl;
*/