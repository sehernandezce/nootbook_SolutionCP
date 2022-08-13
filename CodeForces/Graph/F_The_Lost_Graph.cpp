/*
Problem name: F. The Lost Graph
Algorithm or Logic: Reverse dfs 
Complexity: O(n)
Link: https://codeforces.com/group/2Cle9xU7oR/contest/388771/problem/F
More info: Grafo con un arreglo donde el valor ai es el padre de la posicion i.

function dfs(v)
begin
    visited[v] := true
    print("in " + v)
    for k := 1 : n do
    begin
        if adjacent(v, k) and not visited[k] do
        begin
            dfs(k)
        end
    end
    print("out " + v)
end

*/

#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define PB push_back
#define endl '\n'

typedef long long ll;

const int oo = 1*1e9+10;
const int MAXN = 1e5+5;
int graph [MAXN];

void solv(){
    int n,k,parent;
    string line;

    cin >> n >> line >> parent;
    graph[parent]=parent;   
    
    while(cin >> line){
        cin >> k;
        if(line == "in"){
            graph[k]=parent;
            parent = k;
        }else if(line == "out"){
            parent = graph[k];
        }
    }
    
    for(int i=1; i<=n; i++){
        if(i != graph[i]) cout << i << " " << graph[i] << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); //freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout); //freopen("output.txt", "w", stdout);       
    #endif
    
    solv(); 
    /*
    int t;
    cin >> t;
    for(int i=0; i<t; i++) solv();   
    */

    return 0;
}