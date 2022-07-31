/*
Algorithm or Logic: Para que se pueda formar un rectangulo. El triangulo que se forma en un lado debe tener la misma altura en el lado opuesto de la mesa.
Se colocan las patas asi: 
		             | La mayor
La siguiente mayor  |       | La siguiente de los menores
              La menor | 
La diferencia de los dos menores tiene que ser igual a la diferencia de los dos mayores, asi puedes ubicar las dos mas grandes en un extremo y se mantiene la proporcion con la inclinacion.

Complexity: 1
Link: https://codeforces.com/problemset/gymProblem/102569/K
*/

#include <bits/stdc++.h>
 
 
using namespace std;
 
vector <int> vec;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int a;
    for(int i=0; i<4; i++){
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());

    if(vec[3]-vec[2]==vec[1]-vec[0] && vec[3]-vec[1]==vec[2]-vec[0]) cout << "YES" << endl;
    else cout << "NO" << endl;
   
    return 0;     
}
