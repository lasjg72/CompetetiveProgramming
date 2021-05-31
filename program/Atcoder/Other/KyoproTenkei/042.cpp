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
    int k;
    cin >> k;
    ll ans = 0;
    if(k%9 != 0){
        cout << ans << endl;                
        return 0;
    }
    vector<ll> dp(k+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= 9; j++){
            if(i-j < 0) continue;
            dp[i] = (dp[i]+dp[i-j])%mod;
        }
    }
    cout << dp[k] << endl;
    return 0;
}