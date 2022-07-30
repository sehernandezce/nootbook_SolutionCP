/*
Algorithm or Logic: Sort and Binary search
Complexity: O(NlogN)
Link: https://codeforces.com/problemset/problem/1676/E
More info: 
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll; 

const int MAXN=2e5+10;
int arr[MAXN];

int binarySearch(int size, int value){ // search -> value O(log)
    int l=0,r=size-1;
    while (l<=r)
    {   
        int mid = ((l+r) >> 1); //(n >> k) n/a^k
        if(arr[mid]>=value) r=mid-1;
        else l=mid+1;
    }
    return l==size ? -1 : l+1; // ans is l  
}

void solv(){  
    //Get input
    int n,q;
    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    } 

        // Sort from largest to smallest
    // For vectors sort(vec.rbegin(),vec.rend());
    //int n=sizeof(arr)/sizeof(arr[0]); // Get the size
    //For arrays
    sort(arr,arr+n); 
    reverse(arr,arr+n);
    
    //Accumulate values
    for(int i=1; i<n; i++){
        arr[i]+=arr[i-1];
    }

    //query
    int qq;
    while(q>0){
        cin >> qq;
        cout << binarySearch(n,qq) << endl;
        q--;
    }
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