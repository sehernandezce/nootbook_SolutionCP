//My Vengeance Ends Now! Ω GOW Ω
#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0)
#define precise(ans,k) fixed << setprecision(k) << ans //k digit
using namespace std;

const short n = 9;
short board[n+2][n+2];
bool flag = 0;

bool checkCub()
{   
    for(short i2 = 0; i2 < n/3; i2++)
    {
        for(short j2 = 0; j2 < n/3; j2++)
        {
            short vis[n+2];
            for(short a = 0; a <= n; a++) vis[a] = 0;

            short ii = i2*3, jj = j2*3;
            for(short i = 0; i < n/3; i++)
            {
                for(short j = 0; j < n/3; j++)
                {
                    vis[board[i+ii][j+jj]] += 1;
                }
            }

            for(short a = 1; a <= n; a++) if(vis[a] != 1) return false;
        }
    }

    return true;
}

bool checkRow()
{   
    short vis[n+2];
    for(short i = 0; i < n; i++)
    {   
        for(short a = 0; a <= n; a++) vis[a] = 0;
        for(short j = 0; j < n; j++)
        {
            vis[board[i][j]] += 1;
        }
        for(short a = 1; a <= n; a++) if(vis[a] != 1) return false;
    }
    return true;
}

bool checkCol()
{   
    short vis[n+2];
    for(short j = 0; j < n; j++)
    {   
        for(short a = 0; a <= n; a++) vis[a] = 0;
        for(short i = 0; i < n; i++)
        {
            vis[board[i][j]] += 1;
        }
        for(short a = 1; a <= n; a++) if(vis[a] != 1) return false;
    }
    return true;
}

bool check()
{
    return checkCol() && checkRow() && checkCub();
}

string hashF()
{
    string h = "";
    for(short i = 0; i < n; i++)
    {
        for(short j = 0; j < n; j++)
        {   
            if(board[i][j] == 0) h+=".";
            else h+=to_string(board[i][j]);
        }
    }
    return h;
}

void hashRev(string& h)
{
    for(short i = 0; i < n; i++)
    {
        for(short j = 0; j < n; j++)
        {
            if(h[i*n+j] == '.') board[i][j] = 0;
            else board[i][j] = (h[i*n+j] - '0');
        }
    }
}

void print()
{
    cout << "|";
    for(int j = 0; j < n; j++)
    {
        cout << "---|";
    }
    cout << "\n";
    for(short i = 0; i < n; i++)
    {   
        cout << "| ";
        for(short j = 0; j < n; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << "\n|";
        for(int j = 0; j < n; j++)
        {
            cout << "---|";
        }
        cout << '\n';
    }
}

void go(short i, short j)
{    
    if(flag || i == n)
    {   
        flag = 1;
        return;
    }
    if(j == n)
    {   
        go(i+1, 0);
        return;
    }
    if(board[i][j] != 0)
    {   
        go(i, j+1);
        return;
    }
    
    short vis[n+2];
    for(short a = 0; a <= n; a++) vis[a] = 0;

    for(short b = 0; b < n; b++) vis[board[i][b]] = 1;
    for(short b = 0; b < n; b++) vis[board[b][j]] = 1;
    
    short ii = (i/3)*3, jj = (j/3)*3;
    for(short a = 0; a < n/3; a++)
    {
        for(short b = 0; b < n/3; b++)
        {
            vis[board[a+ii][b+jj]] = 1;
        }
    }
    
    for(short a = 1; a <= n; a++)
    {
        if(vis[a]) continue;
        board[i][j] = a;
        go(i, j+1);
        if(flag) return;
    }
    board[i][j] = 0;
    return;
}


int main()
{   
    FAST;
    int t; cin >> t;
    while(t--)
    {   
        flag = 0;
        string s; cin >> s;
        hashRev(s);
        go(0,0);
        if(flag && check())
        {
            cout << "Y\n";
            cout << hashF() << '\n';
            // print();
        }
        else cout << "N\n";
    }
    return 0;
}
//Refrain from coding until you are sure that your algorithm is both correct and fast enough !!!