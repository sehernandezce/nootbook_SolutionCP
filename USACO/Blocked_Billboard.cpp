/*
Problem name: Blocked Billboard
Algorithm or Logic: Geometry simple
Complexity: O(1)
Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=759
More info:
*/


#include <bits/stdc++.h>

#define forn(i, n) for (ll i = 0; i < (ll)(n); i++)
#define foran(i, a, n) for (ll i = (ll)(a); i < (ll)(n); i++)
#define precise(n, k) fixed << setprecision(k) << n
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr); // cout.tie(0);
#define endl '\n'

using namespace std;

typedef long long ll;
void rwArchive();

const ll MAXN = 1e6 + 5;

template <class T>
struct Rectangle
{
    T x1, y1, x2, y2;
    //T h, w;

    Rectangle() {}
    Rectangle(T x1, T y1, T x2, T y2):x1(x1),y1(y1),x2(x2),y2(y2) {}
    
    T area()
    {
        return (y2-y1)> 0 && (x2-x1)>0 ? (y2-y1)*(x2-x1): -1;
    }

    Rectangle intersect(Rectangle &obj2){
        Rectangle ans(max(x1,obj2.x1),max(y1,obj2.y1),min(x2,obj2.x2),min(y2,obj2.y2));
        return ans;
    }

    T area_inter(Rectangle &obj2){
        return intersect(obj2).area();
    }
};

int main()
{
    IO;
     rwArchive();
    Rectangle <int> rec1, rec2, rec3;

    cin >> rec1.x1 >> rec1.y1 >> rec1.x2 >> rec1.y2;
    cin >> rec2.x1 >> rec2.y1 >> rec2.x2 >> rec2.y2;
    cin >> rec3.x1 >> rec3.y1 >> rec3.x2 >> rec3.y2; 

    int areatotal = rec1.area() + rec2.area();
    //cout << rec1.area() << endl;
    //cout << rec2.area() << endl;
    //cout << rec3.area() << endl;
    int area_inter = max(rec1.area_inter(rec3),0) + max(rec2.area_inter(rec3),0);
    //cout << rec2.area_inter(rec3) << endl;
    int ans = areatotal - area_inter;

    cout << ans << endl;
    

    return 0;
}

void rwArchive()
{
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
     freopen("billboard.in", "r", stdin);
     freopen("billboard.out", "w", stdout);
    //#endif
}

// By Seishi
