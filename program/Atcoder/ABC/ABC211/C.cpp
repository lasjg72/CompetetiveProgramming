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
const int mod = 1e9+7;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> num(n, 0);
    int tmp = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'i'){
            tmp++;
            tmp %= mod;
        }
        if(s[i] == 'a'){
            num[i] += tmp;
        }
    }
    tmp = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'a'){
            tmp += num[i];
            tmp %= mod;
        }
        if(s[i] == 'd'){
            num[i] = tmp;
        }
    }
    tmp = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'd'){
            tmp += num[i];
            tmp %= mod;
        }
        if(s[i] == 'u'){
            num[i] = tmp;
        }
    }
    tmp = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'u'){
            tmp += num[i];
            tmp %= mod;
        }
        if(s[i] == 'k'){
            num[i] = tmp;
        }
    }
    tmp = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'k'){
            tmp += num[i];
            tmp %= mod;
        }
        if(s[i] == 'o'){
            num[i] = tmp;
        }
    }
    tmp = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'o'){
            tmp += num[i];
            tmp %= mod;
        }
        if(s[i] == 'h'){
            num[i] = tmp;
        }
    }
    tmp = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'h'){
            tmp += num[i];
            tmp %= mod;
        }
        if(s[i] == 'c'){
            num[i] = tmp;
        }
    }
    ll ans = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'c'){
            ans += num[i];
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}