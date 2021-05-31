#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>

using namespace std;
using ll = long long;

string s;
map<int, char> mp, num;

int solve(string t){
    map<int, char> mp2 = mp;
    map<int, char> num2 = num;
    for(int i = 0; i < 4; i++){
        int now = t[i]-'0';
        if(s[now] == 'o'){
            if(num2[now] > 0) num2[now]--;
            if(mp2['o'] == 0) continue;
            mp2['o']--;
            
        }else if(s[now] == 'x'){
            return 0;
        }
    }
    for(int i = 0; i < 10; i++){
        if(num2[i] > 0) return 0;
    }
    if(mp2['o'] == 0) return 1;
    else return 0;
}

int main()
{
    cin >> s;
    
    for(int i = 0; i < 10; i++){
        mp[s[i]]++;
        if(s[i] == 'o') num[i] = 1;
    }
    if(mp['o'] > 4) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < 10; i++){
        string s = "000";
        s += (i+'0');
        ans += solve(s);
        //if(solve(s)) cout << s << endl;
    }
    for(int i = 10; i < 100; i++){
        string s = "00";
        s += to_string(i);
        ans += solve(s);
        //if(solve(s)) cout << s << endl;
    }
    for(int i = 100; i < 1000; i++){
        string s = "0";
        s += to_string(i);
        ans += solve(s);
        //if(solve(s)) cout << s << endl;
    }
    for(int i = 1000; i < 10000; i++){
        string s = to_string(i);
        ans += solve(s);
        //if(solve(s)) cout << s << endl;
    }
    cout << ans << endl;
    return 0;
}