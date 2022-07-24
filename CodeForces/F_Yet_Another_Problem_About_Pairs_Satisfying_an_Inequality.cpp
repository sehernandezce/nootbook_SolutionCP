/*
Algorithm or Logic: Binary Search
Complexity: O(n*nlog n)
Link: https://codeforces.com/contest/1703/problem/F
More info:
*/

#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define PB push_back
#define endl '\n'

typedef long long ll; 

const int MAXN=2*1e5+10;

int bs(int l, int r, vector<int> &v, int &val){ // 0 a n-1 ; Binary search
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(v[mid]>=val) r=mid-1;
        else l=mid+1;
    }
    return l;
}
void solv(){
    int n;
    cin >> n;
    int a[n+1];
    for(int i=1; i<n+1; i++){
        cin >> a[i];
        
    }

    long long ans=0;
    vector <int> subi;
    for(int i=1; i<n+1; i++){
        if(a[i]<i){
            ans+= (long long) (bs(0,subi.size()-1,subi,a[i]));
            //ans+=(long long)(lower_bound(subi.begin(), subi.end(), a[i]) - subi.begin()); // Busca el primero que no sea menor a a[i]
            subi.PB(i);
        }
    }
    cout << ans << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t; 
    for(int i=0; i<t; i++) solv();
    
    return 0;
}

