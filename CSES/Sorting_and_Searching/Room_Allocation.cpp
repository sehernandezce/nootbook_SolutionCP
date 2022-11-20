/*
Problem name: Room Allocation
Algorithm or Logic: Logic ans sort
Complexity: O(nlogn)
Link: https://cses.fi/problemset/task/1164
More info:
*/

//Sebastian "Seishi" GG
#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

typedef long long ll;

const int MAXN = 100010;

struct client{
    int id, hour, arOrDep;
    bool operator < (const client &other) const{
        if(hour == other.hour){
            if(arOrDep == other.arOrDep)
                return id < other.id;
            return arOrDep > other.arOrDep;
        }
        return hour < other.hour;
    }
};

int main(){
    IO;
    int n; cin >> n;
    vector <client> customers(2*n);

    for(int i = 0; i < n; i++){
        int ax, bx; cin >> ax >> bx;
        client customerArrival = {i, ax, 1}, customerdeparture = {i, bx, -1};
        customers[i] = customerArrival;
        customers[i+n] = customerdeparture;
    }

    sort(customers.begin(),customers.end());

    stack <int> room;
    for(int i = n; i >=1; i--){
        room.push(i);
    }

    vector <int> allocated(n);
    int mxclients = 0, clients = 0;
    for(auto cl: customers){
        clients += cl.arOrDep;
        if(cl.arOrDep == 1){
            int rom = room.top();
            room.pop();
            allocated[cl.id] = rom;
        }else{
            int rom = allocated[cl.id];
            room.push(rom);
        }
        mxclients = max(mxclients, clients);
    }

    cout << mxclients << endl;
    for(auto val: allocated){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}