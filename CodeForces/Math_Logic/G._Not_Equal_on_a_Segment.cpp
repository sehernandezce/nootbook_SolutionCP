/*
Algorithm or Logic: Calcular la primera posición a la izquierda donde el numero sea diferente.
    Calculate the first position to the left where the number is different.
Complexity:  O(n)
Link: https://codeforces.com/group/2Cle9xU7oR/contest/388576/problem/G
More info: 
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int MAXN=2*1e5+10;
int arr[MAXN];
int first_leftdif [MAXN];

void solv(){
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // input
    int n,m,l,r,x;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    // First number different to the left of arr[i]
    first_leftdif [0]=-1;
    for(int i=1; i<n; i++){
        if(arr[i]!=arr[i-1]) first_leftdif[i]=i-1;
        else first_leftdif[i]=first_leftdif[i-1];
    }

    //query
    while(m){
        cin >> l >> r >> x;
        if(arr[r-1]!=x) cout << r << endl;
        else if(first_leftdif[r-1] >= l-1) cout << first_leftdif[r-1]+1 << endl;
        else cout << -1 << endl;
        m--;
    }

    return 0;
}