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

int main()
{
    ll s;
    cin >> s;
    ll mod = 1e9+7;
    vector<ll> dp(s+1, 0);
    dp[0] = 1;
    for(int i = 1; i < s+1; i++){
        for(int j = i-3; j >= 0; j--){
            dp[i] += dp[j];
            dp[i] %= mod;
        }
    }
    cout << dp[s] << endl;
    return 0;
}