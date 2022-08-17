/* REVISAR !!! Aceptado!!!
Problem name: L. Swaps in Permutation
Algorithm or Logic: Breadth_First_Search (BFS) o Depth_first_search (DFS)
Complexity: O(n+m)
Link: https://codeforces.com/group/2Cle9xU7oR/contest/388886/problem/L
https://codeforces.com/problemset/problem/691/D
More info:
*/

#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN= 1000000+10;
int id=0;
vector <int> nodos[MAXN];
vector <int> grafos[MAXN];
vector<int> visited(MAXN);
int idg[MAXN];
int per[MAXN];
 
void bfs(int n,int p){
 
    
    queue<int> pending;   
    pending.push(p);
    visited[p]=true;
    
    grafos[id].push_back(per[p]);
    idg[p]=id;
 
    while(pending.size() > 0){
        int now = pending.front();
        pending.pop();        
        for(int vecino: nodos[now]){
            if(!visited[vecino]){
                visited[vecino]=true;                
                pending.push(vecino);
 
                grafos[id].push_back(per[vecino]);
                idg[vecino]=id;                                                         
            }
        }       
    }
    sort(grafos[id].begin(), grafos[id].end());
    id++; 
}
 
 
 
int main (){
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    int n,m;
    cin >> n;
    cin >> m;
    int a,b;
    
    for(int i=1; i<n+1; i++){
        cin >> per[i];
    }
    
    for(int i=0; i<m; i++){
        cin >> a >> b;
        if(a!=b){
        nodos[a].push_back(b);
        nodos[b].push_back(a);
        }
        
    }
    
    memset(idg, -1, sizeof  idg);
    for(int i=1; i<n+1; i++){
        if(!visited[i]){
            bfs(n,i);                         
        }
        cout <<  grafos[idg[i]].back() << " ";
        grafos[idg[i]].pop_back();           
    }
 
    cout << endl;    
 
    return 0;
}