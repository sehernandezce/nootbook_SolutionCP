/*
Problem name: B - Labyrinth
Algorithm or Logic: BFS
Complexity: O(m*n)
Link: https://vjudge.net/contest/519548#problem/B
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
const ll oo = LLONG_MAX; // ll(5*1e18)+9LL; // LLONG_MIN
const double PI = 3.141592653589793;
void rwArchive();
void USACO();

const ll MAXN = 1e6 + 5;

vector<pair<ll, char>> adj[MAXN];
pair<ll, char> treebfs[MAXN];
char board[1001][1001];

void bfs(ll start, ll n_nodes)
{   
    //cout << n_nodes << endl;
    vector<ll> distance(MAXN+1, -1);
    queue<ll> pending;

    pending.push(start);
    distance[start] = 0;
    treebfs[0] = {start, 'S'};
    treebfs[start] = {start, 'A'};

    while (pending.size() > 0)
    {
        ll now = pending.front();
        pending.pop();
        //cout << "now: " << now << endl;

        for (auto neig : adj[now])
        {
            if (distance[neig.first] == -1)
            {
                //cout << "neig: " << neig.first << endl;
                distance[neig.first] = distance[now] + 1;
                pending.push(neig.first);
                treebfs[neig.first] = {now, neig.second};
            }
        }
    }
}

string climb_tree(ll start, ll end)
{

    string road = "";

    if(treebfs[end].first == 0) return road;

    while (end != start)
    {
        pair<ll, char> father = treebfs[end];
        road += father.second;
        end = father.first;
    }

    reverse(road.begin(), road.end());
    return road;
}

void makegraph(ll i, ll j, ll m, ll n, ll &n_nodes)
{
    ll id = (i)*m + (j + 1);
    
    if (i + 1 < n)
    {
        if (board[i + 1][j] != '#')
        {
            ll id2 = ((i + 1)) * m + (j + 1);
            adj[id].push_back({id2, 'D'});
            adj[id2].push_back({id, 'U'});
            //cout <<  id << " <-> " << id2 << endl;
            
        }
    }

    if (j + 1 < m)
    {
        if (board[i][j + 1] != '#')
        {
            ll id2 = (i)*m + ((j + 1) + 1);
            adj[id].push_back({id2, 'R'});
            adj[id2].push_back({id, 'L'});
            //cout <<  id << " <-> " << id2 << endl;
        }
    }
}

int main()
{
    IO;
    rwArchive(); // USACO();

    ll n, m;
    cin >> n >> m;

    forn(i, n)
    {
        forn(j, m)
        {
            cin >> board[i][j];
        }
    }

    ll start, end, n_nodes = 0;
    forn(i, n)
    {
        forn(j, m)
        {
            char c = board[i][j]; // (i)*m + (j + 1) 
            if (c == '#')
                continue;
            if (c == 'A')
                start = (i)*m + (j + 1);
            if (c == 'B')
                end = (i)*m + (j + 1);
            makegraph(i, j, m, n, n_nodes);
            n_nodes ++;
        }
    }

    bfs(start, n_nodes);
    string ans = climb_tree(start,end);

    if(ans.size() > 0) cout << "YES \n" <<ans.size() << "\n" << ans << endl;
    else cout << "NO" << endl;

    return 0;
}

void rwArchive()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void USACO()
{

    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
}

// By Seishi
