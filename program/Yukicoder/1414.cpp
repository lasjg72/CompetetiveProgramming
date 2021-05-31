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
const int mod = 1000000007;

ll calc(ll x){
    ll num = 0;
    for(int i = 1; i <= 9; i++){
        num += (x * i)%mod;
        num %= mod;
    }
    return num;
}

int main()
{
    string n;
    cin >> n;
    int len = n.size();
    vector<vector<ll>> dp(len, vector<ll>(2, 0));
    
    ll ans = 0;
    cout << ans << endl;
    return 0;
}