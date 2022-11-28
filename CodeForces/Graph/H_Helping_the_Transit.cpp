// Sebastian "Seishi" GG

/*
Problem name: H. Helping the Transit
Algorithm or Logic: Algorithm Tarjan's Strongly Connected Component (SCC)
Complexity: O(n + m)
Link: https://codeforces.com/gym/103960/problem/H
More info:
*/

/*
Tutorial: https://www.youtube.com/watch?v=wUgWX0nc4NY&ab_channel=WilliamFiset
Description:
1. Usar tarjan para hallar los componentes fuertemente conectados.
2. Mirar: 
    Puede llegar otra componente a mi componente InN
    Si puede puedo llegar a alguna componente OutN
3. Tomar aquellas componente a las que no se pude llegar o no puedo llegar.
La respuesta sera el maximo numero, entre estas.
*/

#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

typedef long long ll;

// Algorithm Tarjan's Strongly Connected Component (SCC) O(m + n)
const int MAXN = 10010;
vector<int> adj[MAXN];
stack <int> stk;
int ids[MAXN], low[MAXN], onStack[MAXN];
int id = 0, numSCCCount = 0;

void dfs(int at){
    stk.push(at); 
    onStack[at] = 1;
    ids[at] = low[at] = id++; // Se asigna id de componente
    for(auto to: adj[at]){
        if(ids[to] == -1) dfs(to);
        if(onStack[to]) low[at] = min(low[at], low[to]); // Se toma el menor id componente entre el padre y el hijo o vecino.
    }
    /* Si ya se recorrio todo desde ese punto y el menor id componente
    es el mismo id del node entonces revise la pila haber si exite un
    id componente menor que el propio.
    La pila permite colocar los nodos que estan en la misma componente, 
    estos seran todo los nodos que estan por encima de at, en ese momento.
    */
    if(ids[at] == low[at]){ 
        while(stk.size()){
            int node = stk.top();
            stk.pop(); onStack[node] = false;
            low[node] = ids[at];
            if(node == at) break;
        }
        numSCCCount++; 
    }
}

void tarjan(int n){
    memset(ids,-1, sizeof ids);
    for(int i = 1; i <= n; i++){
        if(ids[i] == -1) dfs(i);
    }
}
//

int inN[MAXN], outN[MAXN];
int main()
{
    IO;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int at, to; cin >> at >> to;
        adj[at].push_back(to);
    }
    tarjan(n);
    set <int> scc;
    for(int i = 1; i <=n; i++){
        //cout << "Comp: " << i << " " << low[i] << endl;
        scc.insert(low[i]);
        for(auto v: adj[i]){
            if(low[i] != low[v]){
                //cout << i << " " << v << endl;
                inN[low[v]]++; // Se puede llegar a la componente de v
                outN[low[i]]++; // Puede el nodo i llegar a alguna componente
            }
        }
    }

    if(numSCCCount == 1) {
        cout << "0" << endl;
        return 0;
    }

    int cont1 = 0, cont2 = 0;
    for(auto i: scc){
        if(!inN[i]) cont1++;
        if(!outN[i]) cont2++;
    }

    //cout << numSCCCount << endl;
    cout << max(cont1,cont2) << endl;

    return 0;
}