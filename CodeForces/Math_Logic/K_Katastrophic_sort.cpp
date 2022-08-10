
/*
Algorithm or Logic: Katastrophic sort 
Complexity:  O(n)
Link: https://codeforces.com/gym/102700/problem/K
More info: 
*/

#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define PB push_back
#define endl '\n'

typedef long long ll;

//const int MAXN=1e5+10;

void solv(){   
    string s1,s2;
    cin >> s1 >> s2; 

    string sax="",s2ax="";
    string a1="",a2="";
    for(int i=0; i< min(s1.size(),s2.size()); i++){
        if(s1[i] - 'a' >= 0) sax+=s1[i], s2ax+=s2[i];
        else {
            a1= s1.substr(i); // for string to int stoi(s1.substr(i));
            a2= s2.substr(i);
            break;
        }
    }

    int cmpS = strcmp(&sax[0],&s2ax[0]); // a b -> cmpS -1 < 0 ; b a -> cmpS 1 > 0
    if(cmpS == 0){

        if(a1.size() == a2.size()){
            int cmpInt= strcmp(&a1[0],&a2[0]);// 1 2 -> cmpInt -1 < 0 ;  2 1 -> cmpInt 1 > 0

            if(cmpInt == 0)  cout << "=" << endl;
            else if(cmpInt > 0) cout << ">" << endl;
            else  cout << "<" << endl;
        } 
        else if(a1.size() > a2.size()) cout << ">" << endl;
        else cout << "<" << endl;
    }
    else if(cmpS > 0) cout << ">" << endl;
    else cout << "<" << endl;
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
    /*
    int t;
    cin >> t;
    for(int i=0; i<t; i++) solv();
    */
    solv();
    
    return 0;
}