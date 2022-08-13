/*
Problem name: A. Artistic Swimming
Algorithm or Logic: Dijkstra's Algorithm
Complexity: O(n^2 + m) ?
Link: https://codeforces.com/gym/103577/problem/A
More info: https://cp-algorithms.com/graph/dijkstra.html
https://brilliant.org/wiki/dijkstras-short-path-finder/
*/

#include <bits/stdc++.h>

using namespace std;

// Templates
#define endl '\n'
#define int long long int 
#define double long double
#define MAX LLONG_MAX
#define MIN LLONG_MIN

typedef int ll;

// Solution
const int MAXN = 1e3+10;

vector <pair<int,int>> graph[MAXN];

/*
ll dijkstra (ll begin, ll end,ll n,ll x){

    priority_queue<pair<ll,ll>> pending; // (−d, x) the current distance to node x is d
    vector <bool> processed (n+1,  false);
    vector <ll> distance(n+1,  MAX);

    distance[begin]=x;
    pending.push({0,begin});

    while(!pending.empty()){
      ll u = pending.top().second;
      pending.pop();
      if (processed[u]) continue;
      processed[u] = true;
      if(u==end) break;
      for (auto v : graph[u]) {
        ll vx = v.first, w = v.second;
        if (distance[u]+w +x < distance[vx]) {
          distance[vx] = distance[u]+w+x;
          pending.push({-distance[vx],vx});
        }
      }
    }

    return distance[end] == MAX ? -1 : distance[end];
}
*/
int dijkstra (int begin, int end,int n,int x){
 
    vector <int> distance(n+1,  MAX);
    queue <int> pending;
 
    pending.push(begin);
    distance[begin]=x;
 
    while(pending.size()>0){
        int u = pending.front(),val;
        pending.pop();
        
        for(auto v: graph[u]){ 
            
 
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
  int n, m, q, ax, bx, p;
  cin >> n >> m >> q;

  for (int i = 0; i < m; i++){
    cin >> ax >> bx >> p;
    graph[ax].push_back({bx,p});
  }

    while(q--){
        cin >> ax >> bx >> p;
        cout << dijkstra(ax,bx,n,p) << endl;
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
