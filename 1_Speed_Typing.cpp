/*
Algorithm or Logic: Speed Typing
Complexity: O(n)
Link: https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb33e/00000000009e7021
More info: https://codingcompetitions.withgoogle.com/kickstart/faq
*/

#include <bits/stdc++.h>
using namespace std;

//#define int long long int
//#define MAX LLONG_MAX
//#define MIN LLONG_MIN
#define F first 
#define S second
#define PB push_back
#define endl '\n'

typedef long long ll;

const int oo= 1*1e9+10;
const int MAXN=1e5+5;

int solv(){
    string s1,s2;
    cin >> s1 >> s2;

    int j=0;
    for(int i=0; i < s2.size(); i++){
        if(s2[i] == s1[j]) {
          j++;
          if(j == s1.size()) return s2.size()-s1.size();	
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);
     /*
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    */
    //solv(); 
    int t,ans;
    cin >> t;
    for(int i=1; i<=t; i++) {
      ans = solv();
      if(ans != -1) cout << "Case #" << i << ": " << ans <<endl;
      else cout << "Case #" << i << ": IMPOSSIBLE" <<endl;
    }

    
    return 0;
}