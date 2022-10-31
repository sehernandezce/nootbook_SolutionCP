/*
Problem name: Blocked Billboard II
Algorithm or Logic: Geometry simple
Complexity: O(1)
Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=783
More info:
*/

#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'
#define forn(a,n) for(ll i = a; i < n; i++)
using namespace std;

void rwArchive();

typedef long long ll;

const int MAXN = 1e6 + 5;

template<class T>
struct rect{
    T x1,y1, x2, y2;
    rect<T>(){}
    rect<T>(T x1, T y1, T x2, T y2):x1(x1),y1(y1),x2(x2),y2(y2){}

    T area(){
     return (x2-x1)*(y2-y1);   
    }

    T areAinterRec(rect <T> r2){
        T xx1 = max(x1,r2.x1);
        T yy1 = max(y1,r2.y1);
        T xx2 = min(x2,r2.x2);
        T yy2 = min(y2,r2.y2);
        rect<T> ans(xx1,yy1,xx2,yy2);
        T b = max(ans.x2 - ans.x1, 0); T h = max(ans.y2 - ans.y1, 0);
        return b*h;
    }

};

template<class T>
bool inter(rect<T> r1, rect<T> r2){
    if(r2.x1 <= r1.x1 && r2.x2 >= r1.x2){
        if(r2.y1 >= r1.y1 && r2.y2>= r1.y2){
            return true;
        }
        if(r2.y1 <= r1.y1 && r2.y2 <= r1.y2){
            return true;
        }
    }

    if(r2.y1 <= r1.y1 && r2.y2 >= r1.y2){
        if(r2.x1 >= r1.x1 && r2.x2>= r1.x2){
            return true;
        }
        if(r2.x1 <= r1.x1 && r2.x2 <= r1.x2){
            return true;
        }
        if(r2.x1 <= r1.x1 && r2.x2 >= r1.x2){
            return true;
        }
    }

    return false;
}

int main()
{
    IO;
    rwArchive();

    rect <int> r1,r2;
    cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
    cin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;

    bool isInter = inter<int>(r1,r2);
    //cout << isInter << endl;
    //cout << r1.area() << endl;
    //cout << r1.areAinterRec(r2) << endl;
    if(isInter) cout << r1.area() - r1.areAinterRec(r2);
    else cout << r1.area();

    cout  << endl;

    return 0;
}

void rwArchive()
{
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
}

// By Sebastian