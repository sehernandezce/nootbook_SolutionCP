/*
Problem name: White-Black Balanced Subtrees
Algorithm or Logic: Depth-first search (DFS)
Complexity: O(n + m)
Link: https://codeforces.com/contest/1676/problem/G
More info:
*/

#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define PB push_back
#define endl '\n'

typedef long long ll;

const int oo = 1*1e9+10;
const int MAXN = 1e5+10;
int color [MAXN];

int col(char c){
    return c == 'W' ? 1 : -1;
}

bool visited [MAXN];
void dfs(int begin,  string &colors,vector <int> graph[]){
    visited[begin] = true;
    color[begin] = col(colors[begin-1]);

    for (auto u: graph[begin]){
        if(!visited[u]){
            dfs(u,colors,graph);            
        }
        color[begin] += color[u];
    }  
}

void solv(){
    int n,ax,ans=0;
    string colors;

    cin >> n;
    vector <int> graph[n+1];    
    for(int i=2; i<=n; i++){
        cin >> ax;
        graph[ax].PB(i);
    }
    
    cin >> colors;
    dfs(1,colors,graph);

    for(int i=1; i<=n; i++){
        if(color[i] == 0) ans++;
    }

    cout << ans << endl;
    
    memset(visited, false, sizeof visited);    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); //freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout); //freopen("output.txt", "w", stdout);       
    #endif
    
    //solv(); 
    
    int t;
    cin >> t;
    for(int i=0; i<t; i++) solv();   

    return 0;
}