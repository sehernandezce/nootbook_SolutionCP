/*
Problem name: A. Artistic Swimming
Algorithm or Logic: Dijkstra's Algorithm
Complexity: O(n^2 + m) 
Link: https://codeforces.com/gym/103577/problem/A
More info: https://cp-algorithms.com/graph/dijkstra.html
https://brilliant.org/wiki/dijkstras-short-path-finder/
*/

#include <bits/stdc++.h>

using namespace std;

// Templates
#define endl '\n'
#define int long long
#define MAX LLONG_MAX

// Solution
const int MAXN = 1e3+10;

vector <pair<int,int>> graf[MAXN];

int dijkstra (int begin, int end,int n,int x){ // minimum path with weights begin to end 

    vector <int> distance(n+1,  MAX);
    queue <int> pending;

    pending.push(begin);
    distance[begin]=x;

    while(pending.size()>0){
        int u = pending.front(),val;
        pending.pop();
        
        for(auto v: graf[u]){ 
          
            val= distance[u] + v.second + x;            
            if(val < distance[v.first]){
               distance[v.first]=val;
               pending.push(v.first);
            }           
        }
    }


    return distance[end] == MAX ? -1 : distance[end];
}

void solve(){
  int n, m, q, ax, bx, p, ans=0;
  cin >> n >> m >> q;

  for (int i = 0; i < m; i++){
    cin >> ax >> bx >> p;
    graf[ax].push_back({bx,p});
    //graf[bx].push_back({ax,p});
  }

    while(q--){
        cin >> ax >> bx >> p;
        ans = dijkstra(ax,bx,n,p);

        cout << ans << endl;
    }
  

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  // Only local using my exc command.
  #ifndef ONLINE_JUDGE
      // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
  #endif

   solve();

  return 0;
}
