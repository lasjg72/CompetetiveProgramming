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

const int MAX = 5100000;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll modpow(int x, int n){
    if(n == 0) return 1;
    else if(n%2){
        return (modpow(x, n-1)*x)%MOD;
    }else{
        return (modpow(x, n/2)*modpow(x, n/2))%MOD;
    }
}

ll dp[100005][2];

int main()
{
    COMinit();
    string L;
    cin >> L;
    int n = L.size();
    // dp[][0]: 不明 dp[][1]: 確定
    dp[0][0] = 1;
    //dp[0][1] = 1;
    for(int i = 0; i < n; i++){
        // a+b 0
        if(L[i] == '1'){
            dp[i+1][1] = (dp[i][1]+dp[i][0])%MOD; 
        }else{
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1];
        }
        
        // a+bのi桁目が1
        if(L[i] == '1'){
            dp[i+1][0] = (dp[i+1][0]+(dp[i][0]*2)%MOD)%MOD;
            dp[i+1][1] = (dp[i+1][1]+(dp[i][1]*2)%MOD)%MOD;
        }else{
            dp[i+1][1] = (dp[i+1][1]+(dp[i][1]*2)%MOD)%MOD;
        }
    }
    int ans = (dp[n][1]+dp[n][0])%MOD;
    cout << ans << endl;
    return 0;
}