/*
Problem name: UVa 00200 - Rare Order
Algorithm or Logic: TopoSort
Complexity: O(1)
Link: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=136
More info:
*/

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(s) s.begin(),s.end()
#define len(s) (int)s.size()
#define precise(ans,k) fixed << setprecision(k) << ans //k digit
#define MAX LLONG_MAX // INT_MAX
#define MIN LLONG_MIN // INT_MIN

typedef long long ll;
typedef double lf;

const int N = 'Z' - 'A';
const ll oo = 1e18;
const ll MOD = 1e9 + 7;

vector<string> lst;

vector<int> adj[N+5];
vector<int> inGrade(N+5, 0);
vector<int> vis(N+5, 0);
vector<int> topSort;

void go(){
    queue<int> q;
    for(int i = 0; i <= N; i++) if(inGrade[i] == 0 && vis[i]) q.push(i);
    while(q.size()){
        int node = q.front(); q.pop();
        topSort.pb(node);
        for(int y: adj[node]) if(--inGrade[y] == 0) q.push(y);
    }
}

int main(){
    #ifdef LOCALNZN
       freopen("input.txt", "r", stdin); 
       //freopen("output.txt", "w", stdout);  
    #else
        #define endl '\n'
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while(cin >> s){
        if(s == "#") break;
        lst.pb(s);
    }
    int n = len(lst);

    int root = lst[0][0] - 'A';
    vis[root] = 1;
    for(int i = 0; i < n-1; i++){
        int j = 0;
        while(j < len(lst[i]) && j < len(lst[i+1]) && lst[i][j] == lst[i+1][j]){
            j++;
        }
        if(j >= len(lst[i]) || j >= len(lst[i+1])) continue;
        int u = lst[i][j] - 'A', v = lst[i+1][j] - 'A';
        adj[u].pb(v);
        inGrade[v]++;
        vis[u] = vis[v] = 1;
    }
    go();
    
    for(int i = 0; i < len(topSort); i++){
        cout << (char)(topSort[i] + 'A');
    }
    cout << endl;
    
    return 0;
}