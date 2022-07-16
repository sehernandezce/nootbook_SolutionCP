/*
Algorithm: Binary search
Complexity: NlogN
Link: https://codeforces.com/problemset/problem/195/A
#include <bits/stdc++.h>
*/

 
using namespace std;
 
int main (){

    /*
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    */

    int a, b,c,d,t=0;
    cin >> a >> b >> c;
    (a*c)%b==0 ? t=(a*c)/b : t=(a*c)/b + 1;
    
	//Binary search
    int l=1,r=t;
     while(l<=r){
        int mid=(l+r)/2;
        if((a*c)-(t-mid)*a>=0) r=mid-1;
        else l=mid+1;
    }
    cout << l << endl;
    
    return 0;     
}