// Hi! :)
#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0)
#define precise(ans,k) fixed << setprecision(k) << ans //k digit
using namespace std;

string toRoman(long long num)
{   
    // Convert from 1 to 4000
    string sym[13] = {"M", "CM", "D", "CD", "C", "XC", "L","XL", "X", "IX", "V", "IV", "I"};
    int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string nums = "";
    for(int i = 0; i < 13; i++)
    {
        while(num >= val[i])
        {
            num-=val[i];
            nums+=sym[i];
        }
    }

    return nums;
}

long toDecimal(string s)
{
    map<char, int> mp = {{'I',1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D',500}, {'M', 1000}}; 
    map<char, bool> ap;

    bool check = 1;
    long long tot = 0;
    int n = (int)s.size();
    for(int i = 0; i < n; i++)
    {   
        if(ap.count(s[i]) && (s[i] == 'V' || s[i] == 'L' || s[i] == 'D'))
        {
            check = 0;
        }
        ap[s[i]] = 1;
        if(i+1 < n && mp[s[i]] < mp[s[i+1]])
        {   
            if(i-1 >= 0 && s[i] == s[i-1]) check = 0;
            if(s[i] != 'I' && s[i] != 'X' && s[i] != 'C') check = 0;
            if(s[i] == 'I' && (s[i+1] != 'V' && s[i+1] != 'X')) check = 0;
            if(s[i] == 'X' && (s[i+1] != 'L' && s[i+1] != 'C')) check = 0;
            if(s[i] == 'C' && (s[i+1] != 'D' && s[i+1] != 'M')) check = 0;
            tot-=mp[s[i]];
        }
        else 
        {
            if(i-1>=0 && i-2 >=0 && i-3 >=0 && s[i] == s[i-1] && s[i-2] == s[i] && s[i-3] == s[i]) check = 0;
            tot += mp[s[i]];
        }
    }
    if(tot > 0 && check) return tot;
    else return -1;
    return tot;
}

int main()
{
    FAST;
    string nums;
    bool start = 0;
    while(cin >> nums)
    {   
        // if(start) cout << "\n";
        long long num = toDecimal(nums);
        if(num > 0 && toRoman(num) == nums) cout << num;    
        else cout << "This is not a valid number";
        start = 1;
        cout << '\n';
    }    
    return 0;
}
// Refrain from coding until you are sure that your algorithm is both correct and fast enough !!![]