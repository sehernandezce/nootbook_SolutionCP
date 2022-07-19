/*
Algorithm or Logic: Permutando los indices se hayan las combinaciones.
Complexity: O(n*k!)
Link: https://codeforces.com/problemset/problem/124/B
More info: 
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll; 

const int INF= 1*1e9+10;

const int MAXN=8;
int a[MAXN][MAXN];
int iper[MAXN];
int ans= INF;


void solv(int k, int n){
    int mi=INF,ma=-INF;
    
    for(int i=0; i<n; i++){
        int x=0;
        for(int j=0; j<k; j++) (x*=10)+=a[i][iper[j]];
        
        mi=min(mi,x);
        ma=max(ma,x);
    }
    ans=min(ans,ma-mi);
    
}

void permut(int k,int n){
    for(int i=0; i<k; i++) iper[i]=i;
    do{
        //process permutation
        solv(k,n);
    }while(next_permutation(iper,iper+k));
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n,k;
    cin >> n >> k; 
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            char c;
            cin >> c;
            a[i][j]= c - '0';
        }
    }
    permut(k,n);
    cout << ans << endl;
    
    return 0;
}


